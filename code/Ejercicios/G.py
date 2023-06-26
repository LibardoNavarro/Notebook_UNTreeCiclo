from math import sqrt
n = int(input())
bal = input()
l = [0]
x = 0

for i in bal:
    if i == "X":
        x += 1
        l.append(x)
    else:
        l.append(x)
        
subsecuencias = 0

for i in range(3, int(sqrt(n)) + 1):
    xesperadas = ((2 * i) + 2*(i-2))
    oesperadas = ((i - 2) ** 2)

    for j in range((n - i**2) + 1):
        xs = (l[j + (i**2)] - l[j])
        os = i**2 - xs
        if xs == xesperadas and os == oesperadas:
            subsecuencias += 1

print(subsecuencias)