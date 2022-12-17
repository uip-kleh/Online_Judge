sa, ta = map(int, input().split())
sb, tb = map(int, input().split())
print(max(0, min(ta, tb) - max(sa, sb)))