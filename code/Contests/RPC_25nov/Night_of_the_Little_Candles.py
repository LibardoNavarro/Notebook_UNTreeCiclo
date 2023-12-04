def f(x):
  return ((x**3) + 3*(x**2) + (2*x) - 6)

n = int(input())*6
ans = 0
while(n>=18):
  l=2
  r=1817120
  act=0
  while(l<=r):
    mid=(l+r)//2
    if(f(mid)<=n):
      act=mid
      l=mid+1
    else:
      r=mid-1
  n-=f(act)
  ans+=act-1
print(ans, n//6)