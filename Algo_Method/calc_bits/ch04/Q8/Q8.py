n, s = map(int, input().split())
q = int(input())
for i in range(q):
    c, x = map(int, input().split())
    if c == 0: s |= (1 << x)
    elif c == 1: s &= ~(1 << x)
    else: print("on" if (s & (1 << x)) else "off")