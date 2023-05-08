from bisect import bisect_left

n, x = map(int, input().split())
a = sorted(list(map(int, input().split())))
st = set()
for v in a: st.add(v)
for v in a:
    if x + v in st:
        print("Yes")
        exit()
print("No")
