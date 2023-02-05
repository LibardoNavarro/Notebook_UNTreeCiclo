def binary_search(l, n):
    izq = 0
    der = len(l)-1
    while izq <= der:
        mid = (izq + der)//2
        if n == l[mid]:
            return mid
        elif n > l[mid]:
            izq = mid + 1
        else:
            der = mid -1
    return f"{n} no se encuentra en la lista"

l = [3, 4, 5, 7, 8, 9, 34, 567, 999]
print(binary_search(l, 6))