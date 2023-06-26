s = "codeforces"
for i in range(int(input())):
    a = input()
    i = 0
    for j in range(len(a)):
        if a[j] != s[j]:
            i += 1
    print(i)