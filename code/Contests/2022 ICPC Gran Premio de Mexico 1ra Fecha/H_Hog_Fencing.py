import math

p=int(input())
n1=math.floor(p/4)
n2=n1
if p>=((n1+1)*2)+(n2*2):
    n1+=1
print(n1*n2)