import bisect
n = int(input())
w = list(map(int, input().split()))
w_sort = sorted(w)
for val in w: print(bisect.bisect_left(w_sort, val))
