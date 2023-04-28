from math import ceil
for i in range(int(input())):
    c, r, s = map(int, input().split())
    total = c + r
    cucharadas = ceil(total/s)
    print(cucharadas - ceil(r/s), max(cucharadas-r, 0))