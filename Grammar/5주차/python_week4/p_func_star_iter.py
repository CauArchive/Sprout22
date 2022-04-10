def solve(n):
    for i in range(n):
        print('*' * i)


def solve_reverse(n):
    for i in range(n):
        print(" " * (n-i-1), end="")
        print("*" * (i+1))


def solve_star_4(n):
    for i in range(n):
        print(" " * (i), end="")
        print("*" * (n-i))


while True:
    n = int(input())
    if n == 0:
        break
    solve_star_4(n)
