for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    d = {}
    for i in range(n):
        d[l[i]] = i

    l.sort()

    for i in range(1, l):
        izq = 0
        der = i-1
        while(izq <= der):

            mid = (izq+der)//2

            if 