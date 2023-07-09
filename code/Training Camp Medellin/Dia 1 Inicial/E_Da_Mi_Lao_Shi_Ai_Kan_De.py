n = int(input())
mensajes = {}
for case in range(n):
    m = int(input())
    pasa = False
    for mensa in range(m):
        string = input()
        if "bie" in string:
            try:
                mensajes[string] += 1
                continue
            except:
                mensajes[string] = 1
                pasa = True
                print(string)
    if not pasa:
        print("Time to play Genshin Impact, Teacher Rice!")
