N, M = map(int, input().split())
A = list(map(int, input().split()))

INF = 1e18
dp = [[-INF for _ in range(N)] for _ in range(M)]

for i in range(M):
    if i == 0:
        dp[0][0] = A[0]
        for j in range(N-1):
            dp[0][j+1] = max(A[j+1], dp[0][j])
    else:
        for j in range(i, N):
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + A[j] * (i + 1))


print(dp[-1][-1])
