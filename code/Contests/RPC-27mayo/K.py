n, p = list(map(int, input().split()))
sec=input()
siguiente="L"
for i in sec:
    if siguiente==i:
        if siguiente=="L":
            siguiente="R"
        else:
            siguiente="L"
        continue
    else:
        p=p-1
if (p<=0):
    print(0)
else:
    print(p)