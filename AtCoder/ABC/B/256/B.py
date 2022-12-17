def main():
    n = int(input())
    a = list(map(int, input().split()))

    cnt = 0
    for i in range(n):
        pos = 0
        for j in range(i, n):
            pos += a[j]
            if pos >= 4:
                cnt += 1
                break
    print(cnt)

if __name__ == '__main__':
    main()