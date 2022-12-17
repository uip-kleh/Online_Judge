n = int(input())
p = list(map(int, input().split()))
d = dict()
for i in range(n):
    key = i - p[i]
    for j in range(3):
        key += 1
        key %= n
        if not key in d: d[key] = 0
        d[key] += 1

ans = 0
for key, val in d.items():
    ans = max(ans, val)
print(ans)