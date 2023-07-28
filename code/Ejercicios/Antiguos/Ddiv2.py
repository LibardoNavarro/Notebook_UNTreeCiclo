for _ in range(int(input())):
    l = []
    d = {}
    n = int(input())
    for i in range(n):
        s = input()
        l.append(s)
        d[s] = 1
 
    for s in l:
        a = True
        for i in range(1, len(s)):
            if (s[:i] in d and s[i:]) in d:
                print(1, end="")
                a = False
                break
        if a:
            print(0, end="")
 
    print("")