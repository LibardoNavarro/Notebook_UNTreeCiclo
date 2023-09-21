for _ in range(int(input())):
    r, c = map(int, input().split())
    ans = 1
    for i in range(r-1):
        ans *= (c+i)

    fact = 1
    for i in range(2, r):
        fact *= i
    print(int(ans/fact))