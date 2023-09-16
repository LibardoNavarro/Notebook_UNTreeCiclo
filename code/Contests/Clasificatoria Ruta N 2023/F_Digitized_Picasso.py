t=int(input())
for i in range(t):
  n,m=map(int, input().split())
  res=0
  for i in range(m):
    string=input()
    for s in string:
      if s==s.upper():
        res+=1
  if res>=(n*m)/2:
    print("IT IS A PICASSO PAINTING")
  else:
    print("IT IS NOT A PICASSO PAINTING")