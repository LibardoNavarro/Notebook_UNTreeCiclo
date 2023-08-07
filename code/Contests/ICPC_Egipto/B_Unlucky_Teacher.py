cases=int(input())
for i in range(cases):
	q,m=map(int, input().split())
	ans=[["A","B","C","D"] for _ in range(q)]
	answer=["" for _ in range(q)]
	for _ in range(m):
		lista=input().split()
		for j in range(0,q*2,2):
			#print(lista[j], lista[j+1])
			if lista[j+1]=="F" and answer[j//2]=="":
				if lista[j] in ans[j//2]:
					ans[j//2].remove(lista[j])
			elif lista[j+1]=="T":
				answer[j//2]=lista[j]
	for m in range(q):
		if answer[m]=="":
			if len(ans[m])==1:
				answer[m]=ans[m][0]
			else:
				answer[m]="?"
	print(" ".join(answer))