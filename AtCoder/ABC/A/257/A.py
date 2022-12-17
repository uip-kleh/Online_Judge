n, x = map(int, input().split())
s = ""
for i in range(26):
    for j in range(n):
        s += chr(ord('A') + i)
print(s[x - 1])