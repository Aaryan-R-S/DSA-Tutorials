n = int(input())
arr = [int(i) for i in input().split()]
arr_xor = 0

for i in range(n):
    arr_xor ^= arr[i]
    
t = int(input())
print(bin(t^arr_xor).count("1"))