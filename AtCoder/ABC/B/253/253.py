h, w = map(int, input().split())
pos = []
for j in range(h):
    s = input()
    for i in range(w):
        if s[i] == 'o': pos.append([i, j])
print(abs(pos[0][0] - pos[1][0]) + abs(pos[0][1] - pos[1][1]))