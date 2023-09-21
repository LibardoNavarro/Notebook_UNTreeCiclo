t=int(input())
for i in range(t):
  nums=[56,96,36,76,16]
  n=input()
  if(n=="1"):
    print(66)
  elif(n=="0"):
    print(1)
  else:
    n=n[-2:]
    print(nums[(int(n)-1)%5-1])
# # for i in range(1,100):
#   # nums.add((66**i)%100)
# print(nums)
# print((66**1)%100)
# print((66**2)%100)
# print((66**3)%100)
# print((66**4)%100)
# print((66**5)%100)
# print((66**6)%100)
# print((66**7)%100)
# print((66**8)%100)
# print((66**9)%100)
# print((66**10)%100)