from operator import ne


n, k, q = map(int, input().split())
a = list(map(int, input().split()))
dict = {}
for i in range(k): dict[i+1] = a[i]
for l in list(map(int, input().split())):
    if dict[l] != n:
        next_to = False
        for key in dict:
            if dict[l]+1 == dict[key]: next_to = True
        if not next_to: dict[l] += 1
cnt = 1
for key in dict:
    if cnt != k: print(dict[key], end=' ')
    else: print(dict[key])
    cnt += 1