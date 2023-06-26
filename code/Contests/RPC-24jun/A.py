n = input()
l = []
for i in n:
    l.append(int(i))
    
l.sort(reverse=True)

# print(l)
res = ""
for i in l:
    res+=str(i)
    
print(res)