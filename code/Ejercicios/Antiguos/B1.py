import math

n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]

def can_capture(angle):
    max_seen = 0
    prev_x, prev_y = 0, 0
    for x, y in points:
        v1 = (x-prev_x, y-prev_y)
        if prev_x == 0 and prev_y == 0:
            a = 0
        else:
            v2 = (prev_x, prev_y)
            a = math.degrees(math.acos(
                sum(a * b for a, b in zip(v1, v2)) /
                (math.hypot(*v1) * math.hypot(*v2))
            ))
        if a > max_seen:
            max_seen = a
        if max_seen >= angle:
            return True
        prev_x, prev_y = x, y
    return False

lo, hi = 0, 90
while (hi - lo) / max(abs(hi), abs(lo)) > 1e-6:
    mid = (lo + hi) / 2
    if can_capture(mid):
        lo = mid
    else:
        hi = mid

print("{:.9f}".format(lo))