n, d = map(int, input().split())

m = (n // 10) * 10 + (d if n % 10 < d else (d + 10))

print(m)