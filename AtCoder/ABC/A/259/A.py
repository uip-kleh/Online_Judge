n, m, x, t, d = map(int, input().split())
print(t) if m >= x else print(t - (x - m) * d)