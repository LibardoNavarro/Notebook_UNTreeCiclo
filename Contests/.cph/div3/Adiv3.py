for _ in range(int(input())):
    n, d = map(int, input().split())
    s = list(input())
    a = True
    for j in range(n):
        if d > int(s[j]):
            s.insert(j, str(d))
            a = False
            break
    if a:
        s.append(str(d))
    print("".join(s))