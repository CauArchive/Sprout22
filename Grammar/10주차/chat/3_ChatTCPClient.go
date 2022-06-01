/**
* ChatTCPClient.go
Author: Kim, Dong-Wook
Student ID: 20173299
**/

package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
	"os"
	"os/signal"
	"strconv"
	"strings"
	"syscall"
	"time"
)

var maxNicknameLength = 32
var serverName = "127.0.0.1"
var serverPort = "13299"

// Commands List
type commandID int

const (
	CMD_JOIN commandID = iota
	CMD_RTT
	CMD_DM
	CMD_MSG
	CMD_LIST
	CMD_EXIT
)

// software ver
var version = "1.0"

// declare rttTime as global variable
var rttTime time.Time

func isLetter(c rune) bool {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
}

func isCorrectNickname(args []string) (string, error) {
	if len(args) != 2 {
		if len(args) == 1 {
			return "", fmt.Errorf("No nickname")
		}
		if len(args) > 2 {
			return "", fmt.Errorf("No Space allowed for nickname")
		}
	}
	if len(args[1]) > maxNicknameLength {
		return "", fmt.Errorf("Nickname is too long")
	}

	for _, c := range args[1] {
		if !isLetter(c) {
			return "", fmt.Errorf("Nickname must be alphabetic")
		}
	}

	return args[1], nil
}

// func: handle write(means send to server) error
func handleWriteError(conn net.Conn, err error) bool {
	if nil != err {
		conn.Write([]byte(strconv.Itoa(int(CMD_EXIT))))
		conn.Close()
		return true
	}
	return false
}

func handleReadError(conn net.Conn, n int, err error) bool {
	if nil != err {
		conn.Write([]byte(strconv.Itoa(int(CMD_EXIT))))
		conn.Close()
		return true
	}
	if n <= 0 {
		conn.Write([]byte(strconv.Itoa(int(CMD_EXIT))))
		conn.Close()
		return true
	}
	return false
}

// func: handle user interrupt(ctrl-c)
func handleInterrupt(conn net.Conn) {
	c := make(chan os.Signal)
	signal.Notify(c, os.Interrupt, syscall.SIGTERM)
	go func() {
		<-c
		conn.Write([]byte(strconv.Itoa(int(CMD_EXIT))))
		fmt.Println("gg~")
		conn.Close()
		os.Exit(0)
	}()
}

func main() {
	nickName, err := isCorrectNickname(os.Args)
	if nil != err {
		log.Fatalf("%s", err)
	}

	buf := make([]byte, 1024)

	conn, err := net.Dial("tcp", serverName+":"+serverPort)
	if nil != err {
		log.Fatalf("Failed to connect to server: %s", err)
	}

	// Close Connection when program exit
	defer func(conn net.Conn) {
		conn.Write([]byte(strconv.Itoa(int(CMD_EXIT))))
		conn.Close()
	}(conn)

	handleInterrupt(conn)

	// Receive message from server
	go func() {
		for {
			n, err := conn.Read(buf)
			measuredRTT := time.Since(rttTime)
			if handleReadError(conn, n, err) {
				os.Exit(1)
			}
			// If return PING from server, It means RTT
			if string(buf[:n]) == "PING\n" {
				fmt.Printf("RTT: %2.3f ms\n", (float64)(measuredRTT.Microseconds())/1000.0)
			} else {
				fmt.Print(string(buf[:n]) + "\n")
			}
		}
	}()

	// send JOIN command & nickcname to server
	_, err = conn.Write([]byte(strings.Join([]string{strconv.Itoa(int(CMD_JOIN)), nickName}, " ")))
	if handleWriteError(conn, err) {
		log.Fatalf("Failed to set nickname.")
	}

	for {
		// Read Input
		input, inputErr := bufio.NewReader(os.Stdin).ReadString('\n')
		if inputErr != nil {
			log.Println("Error: ", inputErr)
			continue
		}
		input = strings.TrimSuffix(input, "\n")

		// If first word doesn't start with /, it's a message
		if input[0] != '\\' {
			// send message to server
			conn.Write([]byte(strings.Join([]string{strconv.Itoa(int(CMD_MSG)), input}, " ")))
			fmt.Printf("\n")
			continue
		}

		// Handle User Command
		args := strings.Split(input, " ")
		cmd := strings.TrimSpace(args[0])

		switch cmd {
		case "\\dm":
			if len(args) < 3 {
				fmt.Println("usage: /dm <nickname> <message>")
				continue
			}
			conn.Write([]byte(strconv.Itoa(int(CMD_DM)) + " " + strings.Join(args[1:], " ")))
			fmt.Printf("\n")
			// do something
		case "\\rtt":
			rttTime = time.Now()
			_, err := conn.Write([]byte(strconv.Itoa(int(CMD_RTT))))
			if handleWriteError(conn, err) {
				break
			}
		case "\\list":
			// send list command to server
			_, err := conn.Write([]byte(strconv.Itoa(int(CMD_LIST))))
			if handleWriteError(conn, err) {
				break
			}
		case "\\exit":
			_, err := conn.Write([]byte(strconv.Itoa(int(CMD_EXIT))))
			if handleWriteError(conn, err) {
				break
			}
		case "\\ver":
			fmt.Println(version)
		default:
			fmt.Println("invalid option")
		}
	}
}
