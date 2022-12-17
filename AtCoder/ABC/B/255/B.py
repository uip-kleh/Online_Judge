import math
INF = (1 << 21)

n, k = map(int, input().split())
a = list(map(int, input().split()))
points = []
for i in range(n):
    points.append(list(map(int, input().split())))

dict = {}
for i in range(n):
    if not i+1 in a: dict[i] = INF
for key in dict:
    for i in a:
        len = math.sqrt( (points[key][0] - points[i-1][0])**2 + (points[key][1] - points[i-1][1])**2 )
        dict[key] = min(dict[key], len)
max_val = -(1 << 21)
for key in dict:
    max_val = max(max_val, dict[key])
print(max_val)