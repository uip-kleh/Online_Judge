s = input().split('+')
ans = len(s)
for c in s:
    if '*0' in c or '0*' in c or c == '0': ans -= 1
print(ans)
