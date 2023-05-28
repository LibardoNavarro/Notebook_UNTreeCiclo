def f(n):
    return (100/3)*((-1)**n * 2**(1-n) + 1)

n = int(input())
n1 = f(n-1)
print(n1, 100-n1)