nums = input().split()
res=[]
res.append((int(nums[0]+nums[1]+nums[2]),nums[0]+nums[1]+nums[2]))
res.append((int(nums[0]+nums[2]+nums[1]),nums[0]+nums[2]+nums[1]))
res.append((int(nums[2]+nums[1]+nums[0]),nums[2]+nums[1]+nums[0]))
res.append((int(nums[2]+nums[0]+nums[1]),nums[2]+nums[0]+nums[1]))
res.append((int(nums[1]+nums[2]+nums[0]),nums[1]+nums[2]+nums[0]))
res.append((int(nums[1]+nums[0]+nums[2]),nums[1]+nums[0]+nums[2]))
print(max(res)[1])