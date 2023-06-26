for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))

    maxx = 0
    l = 0

    for i in range(n):
        if arr[i] == 0:
            l += 1
            maxx = max(maxx, l)
        else:
            l = 0

    print(maxx)
