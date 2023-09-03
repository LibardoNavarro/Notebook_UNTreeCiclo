while(True):
    n=int(input())
    if n == 0:
        break
    strings=[]
    short=201
    for i in range(n):
        strings.append((input()).lower())
        short=min(short, len(strings[-1]))
    pas=strings[0][0]
    act=""
    for i in range(short):
        pasa=True
        for s in strings:
            if s[i]!=pas[-1]:
                pasa=False
                break
        if not pasa:
            break
        else:
            if i+1==short:
                act=pas
                break
            act=pas
            pas += strings[0][i + 1]
    print(act if act!="" else "*")

