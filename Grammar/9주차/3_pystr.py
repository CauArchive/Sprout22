hello_str = "Hello, world!"
print(hello_str)

print("=============")

for tok in hello_str.split(" "):
    print(tok)

print("=============")

first_str = "First"
second_str = "Second"
print(first_str + " " + second_str)

print("=============")

origin_str = "IsSame?"
cmp_str = "IsSame?"
if origin_str == cmp_str:
    print("Same")
else:
    print("Not same")

print("=============")
