n = [2, 1, 0, 2, 4, 5, 6, 7, 8, 9]

for idx, val in enumerate(n):
    if val % 2 == 0:
        print("*" * (idx+1))
