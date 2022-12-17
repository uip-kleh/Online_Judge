n, x = map(int, input().split())
print("Yes" if (n >> x) & 1 else "No")