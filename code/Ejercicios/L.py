n = int(input())
l = list(map(float, input().split()))
suma = 0
for i in l:
    suma += i**3

print(suma**(1/3))