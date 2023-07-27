#10, 10+n//11
#100, 20+n//111
#1000, 30+n//1111

n=int(input())
pot=0
for i in range(1,11):
    if n<(10**i):
        pot=i-1
        break
res=(pot)*10
res+=n//int("1"+(pot)*"1")
if n<10:
    print(n+1)
else:
    print(res)