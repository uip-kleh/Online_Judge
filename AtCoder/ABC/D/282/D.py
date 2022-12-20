# グローバル変数
even = 0
odd = 0
graph = [list() for i in range(20005)]
color = [-1 for i in range(20005)]
is_binary = True

# 深さ優先探索
def dfs(node, c):
    global even, odd, is_binary
    # basecase
    if color[node] != -1:
        if color[node] != c: is_binary = False # 二部グラフか判定
        return
    
    # step
    color[node] = c
    if c % 2 == 0: even += 1
    else: odd += 1
    for new_node in graph[node]: dfs(new_node, (c+1)%2)

if __name__ == '__main__':
    # input
    n, m = map(int, input().split())
    for i in range(m):
        u, v = map(int, input().split())
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)
    
    ans = n * (n - 1) // 2 - m
    for i in range(n):
        if color[i] != -1: continue # 探索済み
        # init
        even = 0
        odd = 0
        dfs(i, 0)
        ans -= even * (even - 1) // 2
        ans -= odd * (odd - 1) // 2
    
    print(ans if is_binary else 0)

