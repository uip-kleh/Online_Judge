n, m = map(int, input().split())
cnt = 0
for i in [i for i in range(1, n+1)]:
    cnt += min(m // i, n)
print(cnt)
