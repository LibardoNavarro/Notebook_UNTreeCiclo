from math import ceil
for i in range(int(input())):
    c, r, s = map(int, input().split())
    if c == 0 and r==0:
        print(0, 0)
    elif c == 0:
        print(0, 0)
    elif r == 0:
        print(ceil(c/s), ceil(c/s))
    else:
        if r > s:
            print(int(c/s), 0)
        else:
            cucharadas_maximas = ceil((c+r)/s)
            print(ceil(c/s), max(cucharadas_maximas-r, 0))