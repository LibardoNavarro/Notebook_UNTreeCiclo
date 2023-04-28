for _ in range(int(input())):
    n, x1, y1, x2, y2 = map(int, input().split())
    l = [x1, y1, x2, y2]
    centro = n//2
    pos = []
    for i in l:
        if i == centro or i == centro+1:
            pos.append(1)
        elif i > centro:
            pos.append(i-(centro+1) + 1)
        else:
            pos.append(centro - i + 1)
    pos1 = max(pos[0], pos[1])
    pos2 = max(pos[2], pos[3])
    print(abs(pos2 - pos1))