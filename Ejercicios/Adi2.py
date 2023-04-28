def find_x(n, a):
    xor_sum = 0
    for ai in a:
        xor_sum ^= ai
    if xor_sum == 0:
        return 0
    for x in range(1, 28):
        b = [ai ^ x for ai in a]
        xor_b = 0
        for bi in b:
            xor_b ^= bi
        if xor_b == 0:
            return x
    return -1

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print(find_x(n, a))