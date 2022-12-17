n, v = map(int, input().split())
a = list(map(int, input().split()))
can_make = False
for bits in range(1<<n):
    sum = 0
    for i in range(n):
        if bits & (1<<i): sum += a[i]
    if sum == v: can_make = True
print("Yes" if can_make else "No")