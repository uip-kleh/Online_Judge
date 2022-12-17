n, x = map(int, input().split())
a = list(map(int, input().split()))
sum = 0
for i in range(n):
    if x & (1<<i): sum += a[i]
print(sum)