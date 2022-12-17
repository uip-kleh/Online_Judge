import bisect

n, m = map(int, input().split())
a = sorted(list(map(int, input().split())))
b = list(map(int, input().split()))
for val in b: print(bisect.bisect_right(a, val))
