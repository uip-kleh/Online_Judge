def f(n, x):
    n += 1
    for i in range(5): n = n * x + 1
    return n

n, m = map(int, input().split())
l, r = -1, 101
while r - l > 0.0001:
    mid = (l + r) / 2.0
    if f(n, mid) > m: r = mid
    else: l = mid
print(l)