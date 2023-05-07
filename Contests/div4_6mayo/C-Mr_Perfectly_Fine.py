for _ in range(int(input())):
    l = []
    for z in range(int(input())):
        x = input().split()
        l.append([int(x[0]), x[1]].copy())

    l.sort()
    m = 0
    primero = False
    segundo = False
    ambos = False
    m1 = 0
    for clave, valor in l:
        if valor[0] == "1" and primero == False and valor[1] != "1":
            m += int(clave)
            primero = True
        elif valor[1] == "1" and segundo == False and valor[0] != "1":
            m += int(clave)
            segundo = True
        if valor == "11" and ambos == False:
            m1 += int(clave)
            ambos = True
        if (primero and segundo and ambos):
            break
    if (not (primero and segundo)):
        m = 0
    if (m1 != 0 and m!= 0):
        print(min(m1, m))
    elif (m1 == 0 and m!=0):
        print(m)
    elif ((m == 0 and m1!=0)):
        print(m1)
    elif(m1 == 0 and m==0):
        print(-1)