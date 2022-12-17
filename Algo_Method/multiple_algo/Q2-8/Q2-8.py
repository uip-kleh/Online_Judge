from operator import le


def f(x, len):
    cnt = 0
    for l in len: cnt += int(l / x)
    return cnt

n, k = map(int, input().split())
len = list(map(int, input().split()))
l, r = 0, 2e5
while r - l > 1e-8:
    mid = (l + r) / 2
    if f(mid, len) >= k: l = mid
    else: r = mid
print(l)