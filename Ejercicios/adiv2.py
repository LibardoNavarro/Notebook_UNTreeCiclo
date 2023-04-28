for i in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    i = 0
    while True:
        a = True
        l1 = []
        for j in l:
            l1.append(j^i)
        b = l1[0]
        for j in l1[1:]:
            b = b^j
        if b == 0:
            print(i)
            break
        if i == 2**8:
            print(-1)
            break
        i +=1