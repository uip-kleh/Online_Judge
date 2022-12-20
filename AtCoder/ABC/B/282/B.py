n, m = map(int, input().split())
bits = list()
for i in range(n):
    bit = 0
    s = input()
    for i in range(len(s)):
        if(s[i] == 'o'): bit += (1 << i)
    bits.append(bit)

cnt = 0
for i in range(n):
    for j in range(n):
        if i <= j: continue
        if (bits[i] | bits[j]) == (1 << m) - 1: cnt += 1
print(cnt)
