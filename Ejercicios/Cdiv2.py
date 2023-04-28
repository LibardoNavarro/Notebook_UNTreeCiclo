import sys

# Función para leer una línea de números enteros separados por espacio
def read_int_list():
    return list(map(int, input().split()))

# Función para comprobar si un punto (x, y) está por debajo de la parábola y=ax^2+bx+c
def is_below_parabola(x, y, a, b, c):
    return y < a * x * x + b * x + c

# Función para resolver el problema para un caso de prueba
def solve_case():
    # Leer la cantidad de líneas y parábolas
    n, m = read_int_list()

    # Leer las n líneas y guardar sus pendientes (k)
    slopes = set()
    for i in range(n):
        k = int(input())
        slopes.add(k)

    # Leer las m parábolas y para cada una encontrar una línea que no la intersecte ni toque
    for i in range(m):
        a, b, c = read_int_list()
        found = False
        for k in slopes:
            # Comprobar si la línea y=kx está por debajo de la parábola y=ax^2+bx+c en algún punto
            if is_below_parabola(0, c, a, b, c) != is_below_parabola(1, a + b + c, a, b, c):
                found = True
                print("YES")
                print(k)
                break
        if not found:
            print("NO")

# Leer la cantidad de casos de prueba
t = int(input())

# Resolver cada caso de prueba
for i in range(t):
    solve_case()
