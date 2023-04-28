import math

n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]

# Find index of highest point
highest_idx = 0
for i, (x, y) in enumerate(points):
    if y > points[highest_idx][1]:
        highest_idx = i

max_seen = 0
prev_x, prev_y = 0, 0
for x, y in points[highest_idx:] + points[:highest_idx]:
    v1 = (x-prev_x, y-prev_y)
    v2 = (-prev_x, -prev_y)
    a = math.degrees(math.atan2(*v1) - math.atan2(*v2))
    if a < 0:
        a += 360
    if a > max_seen:
        max_seen = a
    prev_x, prev_y = x, y

print("{:.9f}".format(max_seen))
