n = int(input())
a = []
for _ in range(n): a.append(int(input()))
ans = -(1<<63)
minv = a[0]
for i in range(1, n):
    ans = max(ans, a[i] - minv)
    minv = min(minv, a[i])
print(ans)
