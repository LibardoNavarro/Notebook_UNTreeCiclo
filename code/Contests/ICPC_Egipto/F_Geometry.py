n = int(input())
for i in range(n):
    n,m=map(int,input().split())
    if (n==m):
        print("Square")
    else:
        print("Rectangle")