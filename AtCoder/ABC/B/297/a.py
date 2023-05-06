s = input()
uniq = []
R = []
K = None
for i in range(len(s)):
    c = s[i]
    if c == 'B': uniq.append(i%2)
    if c == 'R': R.append(i)
    if c == 'K': K = i
print("Yes" if len(set(uniq)) == 2 and R[0] < K and K < R[1] else "No")
