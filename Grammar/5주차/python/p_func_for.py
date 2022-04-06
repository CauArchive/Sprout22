def initialize_array(n):
    array = []
    for i in range(n):
        array.append(i)
    return array

def print_array(array):
    for i in array:
        print(i, end=' ')

n = []
m = []
k = []

n = initialize_array(n)
m = initialize_array(m)
k = initialize_array(k)

print_array(n)
print_array(m)
print_array(k)
