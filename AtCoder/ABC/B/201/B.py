n = int(input())
l = list()
for i in range(n):
    s, t = input().split()
    l.append([int(t), s])
l.sort()
print(l[-2][-1])