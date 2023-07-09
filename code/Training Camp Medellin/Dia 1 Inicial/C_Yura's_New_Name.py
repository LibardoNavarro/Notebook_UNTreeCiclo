n = int(input())
for i in range(n):
    string = input().replace(" ", "")
    c = 0
    if len(string) == 1 and string == "^":
        c = 1
    elif len(string) == 1 and string == "_":
        c = 2
    else:
        partes = string.split("^")
        np = len(partes)
        if np == 1:
            c += len(partes[0]) + 1
        else:
            for j in range(np):
                lenj = len(partes[j])
                if j == 0 and lenj != 0:
                    c += lenj
                elif j == np - 1 and lenj != 0:
                    c += lenj
                elif lenj != 0 and lenj != 1:
                    c += lenj - 1
    print(c)
