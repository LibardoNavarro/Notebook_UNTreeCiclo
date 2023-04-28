n, x = map(int, input().split())
l = list(map(int, input().split()))
suma = 0
for i in range(n):
    suma += (l[i])**2

suma /= n

if suma != 0:
    c = (x/suma)**0.5

    for i in range(n):
        print(c * l[i], end=" ")
else:
    for i in range(n):
        print(0, end=" ")