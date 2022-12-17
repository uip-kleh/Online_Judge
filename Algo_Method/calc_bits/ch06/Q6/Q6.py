n = int(input())
flag = list()
for i in range(30):
    if (n & (1 << i)): flag.append(i)
print(len(flag))
print(*flag)