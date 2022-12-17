n = int(input())
a = list(map(int, input().split()))

d = dict()
for i in range(len(a)):
    d[a[i]] = i + 1

while len(a) != 2:
    new_a = list()
    for i in range(len(a) // 2):
        new_a.append(max(a[2*i], a[2*i+1]))
    a = new_a
print(d[min(a)])