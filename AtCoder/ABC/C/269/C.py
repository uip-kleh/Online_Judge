n = int(input())
dp = dict()
dp[0] = True
d = 1
for c in reversed(format(n, 'b')):
    new_dp = dict()
    for key, val in dp.items():
        new_dp[key] = True
        new_dp[key + d * int(c)] = True
    d *= 2
    dp = new_dp

for key, val in sorted(dp.items()):
    print(key)