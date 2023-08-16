import math
t = int(input())

while t:
    a,b = map(int, input().split())
    print(math.gcd(abs(a), abs(b)))
    t -= 1