def rotar(matriz, rotacion):
    if rotacion == 90 or rotacion == -270:
        return [list(reversed(columna)) for columna in zip(*matriz)]
    elif rotacion == 180 or rotacion == -180:
        matriz = [list(reversed(columna)) for columna in zip(*matriz)]
        return [list(reversed(columna)) for columna in zip(*matriz)]
    elif rotacion == 270 or rotacion == -90:
        matriz = [list(reversed(columna)) for columna in zip(*matriz)]
        matriz = [list(reversed(columna)) for columna in zip(*matriz)]
        return [list(reversed(columna)) for columna in zip(*matriz)]

figura, num_rotaciones, *rotaciones = map(int, input().split())

figuras = {
    1: [['A', '-', '-'], ['B', '-', '-'], ['C', 'D', '-']],
    2: [['-', '-', 'A'], ['-', '-', 'B'], ['-', 'D', 'C']],
    3: [['-', '-', '-'], ['A', 'B', '-'], ['-', 'C', 'D']],
    4: [['-', '-', '-'], ['-', 'C', 'D'], ['A', 'B', '-']],
    5: [['-', '-', '-'], ['-', 'D', '-'], ['A', 'B', 'C']],
    6: [['-', '-', '-'], ['A', 'B', '-'], ['C', 'D', '-']]
}

matriz = figuras[figura]

for rotacion in rotaciones:
    matriz = rotar(matriz, rotacion)

for row in matriz:
    print("".join(row))