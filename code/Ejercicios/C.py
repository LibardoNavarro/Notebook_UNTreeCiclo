def solve(s):
    if s.count("R") > s.count("B"):
        return -1
    
    b = 0
    n = len(s)
    num_blues = [0]
    for i in range(n):
        if s[i] == "B":
            b += 1
            num_blues.append(b)
        
    for i in range(1, n+1):
        num_red = i -num_blues[i]
        num_blues_der = num_blues[n] - num_blues[i-1]
        if (num_red > num_blues[i]) and (num_blues_der >= )

for i in range(int(input())):
    s = input()