a = input()
b = input()
l = len(a)
l1 = len(b)
if (l == l1):
    pass
elif (l < l1):
    a = "0" * (l1-l) + a
else:
    b = "0" * (l-l1) + b
ans = ""
for i in range(max(l, l1)):
    c = int(a[i])
    d = int(b[i])
    if (c <= 2 and d <= 2) or (c >= 7 and d >= 7):
        ans += "0"
    else:
        ans += "9"

print(ans)