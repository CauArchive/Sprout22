/**
* ChatTCPServer.go
Author: Kim, Dong-Wook
Student ID: 20173299
**/

package main

import (
	"fmt"
	"io"
	"log"
	"net"
	"os"
	"os/signal"
	"strconv"
	"strings"
	"syscall"
)

// software version
var version = "1.0"
var maxClient = 8
var serverName = "localhost"
var serverPort = ":13299"

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

/**
Server Command Struct
id: command id
client: client who sent the command
args: command arguments with proper command
*/
type command struct {
	id     commandID
	client *client
	args   []string
}

// bad word check function to check if the message contains bad words
func badWordCheck(msg string) bool {
	badWords := []string{"i hate professor"}
	for _, badWord := range badWords {
		if strings.Contains(strings.ToLower(msg), badWord) {
			return true
		}
	}
	return false
}

/**
Each client has its own struct
conn: connection with individual client
nick: nickname of the client
commands: channel to receive command from client
*/
type client struct {
	conn     net.Conn
	nick     string
	commands chan<- command
}

// When a client connected with server
// run() will be called and handle the command
func (c *client) run() {
	buffer := make([]byte, 1024)
	for {
		nbytes, err := c.conn.Read(buffer)
		if nil != err {
			if err == io.EOF {
				fmt.Println("Connection closed by client")
			}
			break
		}

		recvMsg := string(buffer[:nbytes])
		args := strings.Split(recvMsg, " ")
		cmd, _ := strconv.Atoi(strings.TrimSpace(args[0]))

		// Parse the command message from client
		// and deliver the command to server
		switch commandID(cmd) {
		case CMD_JOIN:
			c.commands <- command{
				id:     CMD_JOIN,
				client: c,
				args:   args,
			}
		case CMD_RTT:
			c.msg("PING")
		case CMD_DM:
			c.commands <- command{
				id:     CMD_DM,
				client: c,
				args:   args,
			}
		case CMD_MSG:
			c.commands <- command{
				id:     CMD_MSG,
				client: c,
				args:   args,
			}
		case CMD_LIST:
			c.commands <- command{
				id:     CMD_LIST,
				client: c,
			}
		case CMD_EXIT:
			c.commands <- command{
				id:     CMD_EXIT,
				client: c,
			}
		default:
			c.err(fmt.Errorf("invalid command: %d", cmd))
		}
	}
}

func (c *client) err(err error) {
	c.conn.Write([]byte(err.Error() + "\n"))
}

func (c *client) msg(msg string) {
	c.conn.Write([]byte(msg + "\n"))
}

/** server struct
pconn: server connection itself
commands: channel to receive command from client
members: map of client
*/
type server struct {
	pconn    net.Listener
	commands chan command
	members  map[net.Addr]*client
}

// when server starts,
// allocate proper channel and map
func newServer() *server {
	return &server{
		commands: make(chan command),
		members:  make(map[net.Addr]*client),
	}
}

// After server instance created
// run() will be called and handle the command from client
func (s *server) run() {
	for cmd := range s.commands {
		switch cmd.id {
		case CMD_JOIN:
			s.join(cmd.client, cmd.args)
		case CMD_DM:
			s.dm(cmd.client, cmd.args)
		case CMD_MSG:
			s.msg(cmd.client, cmd.args)
		case CMD_LIST:
			s.listMembers(cmd.client)
		case CMD_EXIT:
			s.exit(cmd.client)
		}
	}
}

// When a client joined the server
// create client instance
func (s *server) newClient(conn net.Conn) *client {
	log.Printf("new client has joined: %s", conn.RemoteAddr().String())

	return &client{
		conn:     conn,
		nick:     "anonymous",
		commands: s.commands,
	}
}

// After a client has it own instance
// call join() and check if the nickname is not duplicate and has space to join
func (s *server) join(c *client, args []string) {
	if len(args) < 2 {
		s.reject(c, fmt.Errorf("nick is required"))
		return
	}

	// check if the nickname is duplicate
	for _, others := range s.members {
		if others.nick == args[1] {
			s.reject(c, fmt.Errorf("that nickname is already used by another user. cannot connect"))
			return
		}
	}
	// set user nickname
	c.nick = args[1]

	// check if the user can join the server
	if len(s.members) >= maxClient {
		s.reject(c, fmt.Errorf("chatting room full. cannot connect"))
		return
	}
	// add client to server
	s.members[c.conn.RemoteAddr()] = c
	s.broadcast(c, fmt.Sprintf("%s joined the room", c.nick))
	c.msg(fmt.Sprintf("welcome %s to CAU network class chat room at %s.\nThere are %d users connected.", c.nick, serverName+serverPort, len(s.members)))
}

// Method for Direct Message function
func (s *server) dm(c *client, args []string) {
	if len(args) < 3 {
		c.msg("usage: /dm <nickname> <message>")
		return
	}
	isExist := false
	// Check if there is a user with the nickname
	for _, m := range s.members {
		if m.nick == args[1] {
			isExist = true
			directMsg := strings.Join(args[2:], " ")
			// check if the message contains badword
			if badWordCheck(directMsg) {
				s.exit(c)
				return
			}
			// send direct message to the user
			m.msg("from: " + c.nick + "> " + strings.Join(args[2:], " "))
		}
	}
	// if there is no user with the nickname
	if !isExist {
		c.msg("user not found")
	}
}

// Method for Message function
func (s *server) msg(c *client, args []string) {
	if len(args) < 2 {
		c.msg("message is required, usage: /msg MSG")
		return
	}
	msg := strings.Join(args[1:], " ")
	// check if the message contains badword
	if badWordCheck(msg) {
		s.exit(c)
		return
	}
	// Broadcast message to all members
	s.broadcast(c, c.nick+"> "+msg)
}

// Method for showing joined members(\list)
func (s *server) listMembers(c *client) {
	var membs []string
	// add all joined members data to membs array
	for _, m := range s.members {
		host, port, _ := net.SplitHostPort(m.conn.RemoteAddr().String())
		membs = append(membs, strings.Join([]string{m.nick, host, port}, ", "))
	}
	// send all members data to client
	c.msg(fmt.Sprintf("Users in the room\n%s", strings.Join(membs, "\n")))
}

// Method for broadcast message
func (s *server) broadcast(sender *client, msg string) {
	for addr, m := range s.members {
		// if not the sender, send message to the member
		if sender.conn.RemoteAddr() != addr {
			m.msg(msg)
		}
	}
}

// Method for reject connection
// Used at join() Method to reject connection
func (s *server) reject(c *client, err error) {
	delete(s.members, c.conn.RemoteAddr())
	c.err(err)
	c.conn.Close()
}

// Method for exit
func (s *server) exit(c *client) {
	log.Printf("client has left the chat: %s", c.conn.RemoteAddr().String())

	// Delete client from server
	delete(s.members, c.conn.RemoteAddr())

	// Broadcast message that client has left
	s.broadcast(c, fmt.Sprintf("[%s left. There are %d users now]", c.nick, len(s.members)))

	// Close connection with that client
	c.conn.Close()
}

// func: handle user interrupt(ctrl-c)
func handleInterrupt() {
	c := make(chan os.Signal)
	signal.Notify(c, os.Interrupt, syscall.SIGTERM)
	go func() {
		<-c
		fmt.Println("Bye bye~")
		os.Exit(0)
	}()
}

func main() {
	// create server struct instance when server start
	s := newServer()
	// run server instance
	go s.run()

	pconn, err := net.Listen("tcp", serverPort)
	if nil != err {
		log.Fatalf("Failed to create TCP socket: %s\n", err)
	}
	defer func(conn net.Listener) {
		err := conn.Close()
		if err != nil {
			fmt.Println(err)
		}
	}(pconn)

	s.pconn = pconn
	// Handling Interrupt(Ctrl-C)
	handleInterrupt()

	log.Println("Server is ready to receive on port " + serverPort)

	for {
		conn, err := pconn.Accept()
		if nil != err {
			fmt.Println("Failed to accept TCP connection: ", err.Error())
			continue
		}
		// create client struct instance when client connect
		c := s.newClient(conn)
		// run client instance to receive client input
		go c.run()
	}
}
