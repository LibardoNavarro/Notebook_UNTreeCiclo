n=int(input())
v1=sorted(list(map(int, input().split())))
v2=sorted(list(map(int, input().split())))
c1=0
c2=0
for i in v1:
        for j in v2:
                if i>j:
                        c1+=1
                else:
                        break
for i in v2:
        for j in v1:
                if i>j:
                        c2+=1
                else:
                        break
if(c1>c2):
        print("first")
elif(c2>c1):
        print("second")
else:
        print("tie")