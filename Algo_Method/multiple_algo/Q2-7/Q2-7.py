def f(x): return x * (x + 1) // 2
n = int(input())
for val in list(map(int, input().split())):
    l, r = -1, 2 * 10 ** 9
    while l != r:
        mid = (l + r) // 2
        if f(mid) >= val: r = mid
        else: l = mid + 1
    print(l)