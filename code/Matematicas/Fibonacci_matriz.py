def mult(matriz1, matriz2):
    fila_1 = [matriz1[0][0] * matriz2[0][0] + matriz1[0][1] * matriz2[1][0], matriz1[0][0] * matriz2[0][1] + matriz1[0][1] * matriz2[1][1]]
    fila_2 = [matriz1[1][0] * matriz2[0][0] + matriz1[1][1] * matriz2[1][0], matriz1[1][0] * matriz2[0][1] + matriz1[1][1] * matriz2[1][1]]
    return [fila_1, fila_2]
def mult_vector(matriz, vector):
    a = matriz[0][0] * vector[0] + matriz[0][1] * vector[1]
    b = matriz[1][0] * vector[0] + matriz[1][1] * vector[1]
    return [a, b]
def modulos(matriz, n):
    matriz[0][0] %= n
    matriz[0][1] %= n
    matriz[1][0] %= n
    matriz[1][1] %= n
    return matriz

def exp_bin(b, n, m):
    res = [[1, 0], [0, 1]]
    while n > 0:
        if n % 2 == 1:
            res = mult(modulos(res, m), modulos(b, m))
        b = mult(modulos(b, m), modulos(b, m))
        n //= 2
    return modulos(res, m)
matriz = [[1, 1] , [1, 0]]
vector = [1, 0]
# a = list(map(int, input().split()))
m = exp_bin(matriz, int(input()), 1000000007)
v = mult_vector(m, vector)
print(v[1] % 1000000007)