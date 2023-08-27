n=int(input())
res=0
ult=0
for i in range (1,11):
    if 10**i<=n:
        res+=10
        ult=i
    else:
        break
onces="1"+"1"*ult
for i in range(1,10):
    if int(onces)*i<=n:
        res+=1
    else:
        break
if(n<10):
    res+=1
print(res)