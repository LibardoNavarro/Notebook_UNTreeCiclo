n = int(input())
palabras = input().split()

l = []
for i in range(n):
    l.append(0)

ans = 0
for i in range(n):
    p = palabras[i]
    for j in range(i+1,n):
        p1 = palabras[j]
        for k in range(len(p)):
            if (p[k:] + p[:k] == p1 and l[j] == 0):
                l[j] = 1
print(l.count(0))