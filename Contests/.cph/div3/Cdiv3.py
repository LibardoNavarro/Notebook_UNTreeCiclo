for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    l1 = [str(l[0])] + ([0] * (n-2)) + [str(l[n-2])]

    for i in range(n-2):
        l1[i+1] = str(min(l[i], l[i+1]))

    print(" ".join(l1))