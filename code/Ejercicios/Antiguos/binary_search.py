def binary_search(l, n):
    izq = 0
    der = n-1
    while izq <= der:
        mid = (izq + der) // 2
        if l[mid] == n:
            return mid
        elif l[mid] < n:
            izq = mid + 1
        else:
            der = mid - 1
    return -1

print(binary_search())