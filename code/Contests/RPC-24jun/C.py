n = int(input())


mat =[]
for i in range(31):
    mat.append([])
# print(mat)

maxi = 0
for i in range(n):
    n = input()
    lar = len(n)
    if lar>maxi:
        maxi =lar
    
    for e in range(lar):
        mat[e].append(n[e])

for i in range(maxi):
    dicc = {}
    for e in mat[i]:
        if e in dicc:
            dicc[e]+=1
        else:
            dicc[e]=1
    
    max2 = max(list(dicc.values()))
    
    lres = []
    for e in dicc:
        if dicc[e] ==max2:
            lres.append(e)
    lres.sort()
    print(str(i+1)+": "+" ".join(lres))
            
    