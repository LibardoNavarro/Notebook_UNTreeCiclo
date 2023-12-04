# def gcd(a, b):
#     return a if b == 0 else gcd(b, a % b)

from math import gcd
def lcm(a, b):
    return a // gcd(a, b) * b


t = int(input())
for _ in range(t):
    a, b, c, n = map(int, input().split())
    a += 1
    b += 1
    c += 1
    part1 = n // a + n // b + n // c
    part2 = n // lcm(a, b) + n // lcm(b, c) + n // lcm(c, a)
    div = gcd(a * b, gcd(b * c, c * a))
    part3 = n // ((a*b*c)//div)
    print(part1 - part2 + part3)
