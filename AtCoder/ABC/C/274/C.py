n = int(input())
a = list(map(int, input().split()))
d = dict()
d[1] = 0
for i in range(1, n+1):
    d[2 * i] = d[a[i-1]] + 1
    d[2 * i + 1] = d[a[i-1]] + 1

for i in range(1, 2*n+2): print(d[i])