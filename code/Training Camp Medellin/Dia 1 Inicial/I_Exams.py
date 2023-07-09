n = int(input())
lista = []
for exams in range(n):
    a, b = input().split(" ")
    lista.append((int(a), int(b)))
lista.sort()
dias = 0
for k in range(n):
    if k == 0:
        dias = lista[k][1]
    else:
        if dias <= lista[k][1]:
            dias = lista[k][1]
        else:
            dias = lista[k][0]
print(dias)
