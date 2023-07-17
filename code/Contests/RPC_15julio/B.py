vocales = ["a", "e", "i", "o", "u"]
string = input()
comienza = 1 if string[0] in vocales else 0
n = len(string)
pasa = True
for i in range(1, n):
    if comienza == 1 and string[i] in vocales:
        pasa = False
        break
    elif comienza == 0 and not string[i] in vocales:
        pasa = False
        break
    elif comienza == 0 and string[i] in vocales:
        comienza = 1
    else:
        comienza = 0
if pasa:
    print(1)
else:
    print(0)
