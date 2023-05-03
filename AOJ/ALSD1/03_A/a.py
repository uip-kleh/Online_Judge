s = input().split()
stk = []
for c in s:
    if c in ['+', '-', '*']:
        v1 = stk.pop()
        v2 = stk.pop()
        if c == '+': v3 = v1 + v2
        if c == '-': v3 = v2 - v1
        if c == '*': v3 = v2 * v1
        stk.append(v3)
    else:
        stk.append(int(c))
print(stk[0])
