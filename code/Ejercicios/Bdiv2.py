for i in range(int(input())):
    n = int(input())
    s = list(input())
    for i in range(n):
        s[i] = ord(s[i])
    minimo = min(s)
    s1 = s[::-1]
    s1.remove(minimo)
    s = s1[::-1]
    a = True
    for i in range(n-1):
        if s[i] > minimo:
            s.insert(i, minimo)
            a = False
            break
    
    if a:
        s.append(minimo)

    for i in range(n):
        s[i] = chr(s[i])

    print("".join(s))