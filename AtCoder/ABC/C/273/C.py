import bisect
n = int(input())
a = list(map(int, input().split()))
d = {}
for key in a:
    if not key in d: d[key] = 0
    d[key] += 1

set_a = sorted(set(a))
ans = [0] * n
set_a_size = len(set_a)
for key in set_a:
    index = bisect.bisect_left(set_a, key)
    ans[set_a_size - index - 1] += d[key]
for val in ans: print(val)