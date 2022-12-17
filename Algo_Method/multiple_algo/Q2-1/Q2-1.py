def f(x): return x * (x * (x + 1) + 2) + 3

n = int(input())
l = -1
r = n + 1
while r - l > 0.001:
    mid = (r + l) / 2.0
    if f(mid) > n: r = mid
    else: l = mid
print(l)