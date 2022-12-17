s = input()
d = {}
for c in s: d[c] = 0
for c in s: d[c] += 1
ans = ""
for key in d:
    if d[key] == 1:
        ans = key
        break
print(ans if len(ans)!=0 else -1)