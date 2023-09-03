c=int(input())
for i in range(c):
    n,string=input().split()
    res=[]
    count=0
    len=0
    for s in string:
        if s==")":
            if len>0:
                count+=1
                len-=1
                res.pop()
        else:
            res.append("(")
            len+=1
        #if count!=-1:
        #    res+=s
        #else:
        #    count=0
    print(count*2)