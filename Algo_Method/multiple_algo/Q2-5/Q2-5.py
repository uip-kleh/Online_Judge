import bisect

cnt = 0

n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))
for val in a:
    d = k - val
    cnt += len(a) - bisect.bisect_left(a, d)
print(cnt)
    