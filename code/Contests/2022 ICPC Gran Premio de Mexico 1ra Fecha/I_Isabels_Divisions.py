l = input()
n = int(l)
digitos = 0
for i in l:
    if i != '0':
        if n % int(i) == 0:
            digitos += 1
        
print(digitos)