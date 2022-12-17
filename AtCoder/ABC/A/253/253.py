vec = list(map(int, input().split()))
print("Yes" if vec[1] == sorted(vec)[1] else "No")