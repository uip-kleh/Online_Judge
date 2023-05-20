import sys

sys.setrecursionlimit(500005)
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()

L, Q = na()
qs = []
for i in range(Q):
    qs.append(na())

cuts = [0, L]
for q in qs:
    if q[0] == 1:
        cuts.append(q[1])
cuts.sort()
n = len(cuts)

upper = [-1] * n
sums = [0] * n
for i in range(n-1):
    sums[i] = cuts[i+1] - cuts[i]

def root(x):
    if upper[x] < 0:
        return x
    else:
        upper[x] = root(upper[x])
        return upper[x]

def equiv(x, y):
    return root(x) == root(y)

def unite(x, y):
    x, y = root(x), root(y)
    if x != y:
        if upper[y] < upper[x]:
            x, y = y, x
        upper[x] += upper[y]
        upper[y] = x
    return x == y

ret = []
import bisect
for q in qs[::-1]:
    if q[0] == 1:
        ind = bisect.bisect_right(cuts, q[1]) - 1
        s = sums[root(ind-1)] + sums[root(ind)]
        unite(ind-1, ind)
        sums[root(ind)] = s
    else:
        ind = bisect.bisect_right(cuts, q[1]) - 1
        ret.append(sums[root(ind)])

for v in ret[::-1]:
    print(v)
