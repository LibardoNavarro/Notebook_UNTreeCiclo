string=input()
k=int(input())
n=len(string)
lista=[]
c=1
primera=True
for i in range(n):
    if (i)%k==0 and i!=0:
        primera=False
    if primera:
        lista.append([string[i]])
    else:
        lista[i%k].append(string[i])
for i in lista:
    i.sort()
res=[]
# print(lista)
for i in range(n):
    res.append(lista[i%k][i//k])
print("".join(res))
