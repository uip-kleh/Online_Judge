n = int(input())
flag = 0
for f in list(map(int, input().split())): flag += (1 << f)
print(flag)