n = input()

def isNumber(n):
    # n = str(n1+n2)
    n1 = 0
    n2 =0
    for i in n:
        if i =="4":
            n1+=1
        if i =="7":
            n2+=1
    if (n1+n2)==7 or (n1+n2)==4:
        return True
    else:
        return False
    

n1=0
n2=0
for i in n:
    if i =="4":
        n1+=1
    if i =="7":
        n2+=1
        
if isNumber(str(n1+n2)) or isNumber(n):
    print("YES")
else:
    print("NO")