n,k=map(int, input().split())
cajas=n//k
if n%k==0:
    print(k)
else:
    if n<=k:
        print(n)
    else:
        print(n//(cajas+1))
    # a=((k*(n//k))-((n%k)*k))//(k+1)
    # print((n%k)+a)

    # mod=n%k
    # while(k>mod):
    #     k-=1
    #     mod+=cajas
    # print(k)