n = int(input())
for case in range(n):
    string = input()
    lens = len(string)
    if string == "1":
        print(1)
    elif string == "0":
        print(0)
    else:
        maxUnos = 0
        longitud = 0
        for i in range(-lens + 1, lens):
            if string[i] == "1":
                longitud += 1
            else:
                maxUnos = max(maxUnos, longitud)
                longitud = 0
        maxUnos = max(maxUnos, longitud)
        rest = 0
        if maxUnos >= lens:
            rest = lens**2
        else:
            for j in range(maxUnos):
                rest = max((maxUnos - j) * (j + 1), rest)
                if maxUnos - j == j - 1:
                    break
        print(rest)
