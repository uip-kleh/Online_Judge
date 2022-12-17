import bisect
n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

asum = [0]
bsum = [0]
for v in a: asum.append(asum[-1] + v)
for v in b: bsum.append(bsum[-1] + v)

max_cnt = 0
for i in range(n+1):
    res = k - asum[i]
    if res < 0: continue
    j = min(bisect.bisect_left(bsum, res), m)
    if asum[i] + bsum[j] > k and j > 0: j -= 1
    max_cnt = max(max_cnt, i + j)
print(max_cnt)