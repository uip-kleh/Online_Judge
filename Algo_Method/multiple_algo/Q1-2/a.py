n = int(input())
cnt = 0
while n != 0:
    if n % 2 == 0: n = min(n-1, n/2)
    else: n -= 1
    cnt += 1
print(cnt)
