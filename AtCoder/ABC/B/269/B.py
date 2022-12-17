start, goal = [], []
for i in range(10):
    s = input()
    for j in range(10):
        if s[j] == '#':
            if not start: start = [i+1, j+1]
            goal = [i+1, j+1]
print(*[start[0], goal[0]], sep=' ')
print(*[start[1], goal[1]], sep=' ')