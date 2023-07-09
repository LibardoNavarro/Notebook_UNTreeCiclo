n = int(input())
nums = list(map(int, input().split()))
deposito = sum(nums) / (n + 1)
especial = 2 * deposito
print(especial, end=" ")
for i in range(1, n - 1):
    print(deposito, end=" ")
print(deposito)
