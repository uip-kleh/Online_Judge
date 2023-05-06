h, w = map(int, input().split())
s = []
for _ in range(h): s.append(input().replace("TT", "PC"))
print(*s, sep='\n')
