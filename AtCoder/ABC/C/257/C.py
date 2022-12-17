n = int(input())
ans = 0
vvec = []
s = input()
w = list(map(int, input().split()))
for i in range(n):
    vvec.append([w[i], s[i]])
    if s[i] == '1': ans += 1
vvec = sorted(vvec)
cnt = ans
for i in range(n):
    if vvec[i][1] == '1': cnt -= 1
    else: cnt += 1
    if i < n - 1:
        if vvec[i][0] != vvec[i+1][0]:
            ans = max(ans, cnt)
    else: 
        ans = max(ans, cnt)
print(ans)