n = int(input())
for i in range(n):
    wor = input()
    lis={}
    dif = 0
    for i in wor:
        if i not in lis:
            dif+=1
            lis[i]=1
        else:
            lis[i]+=1

    sumTol =0
    maxi =0
    for i in lis:
        maxi = max(lis[i],maxi)
        sumTol+=lis[i]
    
    print(sumTol-maxi)