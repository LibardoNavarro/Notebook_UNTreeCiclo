def verSiEstaEnODeUno(d, s):
    try:
        d[s]
    except:
        return False
    return True

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
            if (verSiEstaEnODeUno(d, s[:i]) and verSiEstaEnODeUno(d, s[i:])):
                print(1, end="")
                a = False
                break
        if a:
            print(0, end="")

    print("")