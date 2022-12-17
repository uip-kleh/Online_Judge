h, w, n = map(int, input().split())
la = list()
lb = list()
for i in range(n):
    a, b = map(int, input().split())
    la.append(a)
    lb.append(b)

da = dict()
db = dict()
cnt = 1
for val in sorted(set(la)):
    da[val] = cnt
    cnt += 1
cnt = 1
for val in sorted(set(lb)):
    db[val] = cnt
    cnt += 1
for i in range(n):
    print(da[la[i]], db[lb[i]])