def main():
    n, k = map(int, input().split())
    p = list()
    for i in range(n):
        p.append([-sum(list(map(int, input().split()))), i])
    p.sort()

    clear_score = abs(p[k - 1][0]) - 300
    judge = [False] * n
    
    for i in range(n): if abs(p[i][0]) >= clear_score: judge[p[i][1]] = True
    for i in range(n): print("Yes" if judge[i] else "No")


if __name__ == '__main__':
    main()