def judge_pass(max_num, subject, pas):
    cnt = 0
    for score, i in subject:
        if cnt == max_num: break
        if not pas[i]:
            pas[i] = True
            cnt += 1

    return pas

def main():
    n, x, y, z = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    math = list()
    eng = list()
    sum = list()
    pas = dict()

    for i in range(n):
        math.append([-a[i], i])
        eng.append([-b[i], i])
        sum.append([-a[i]-b[i], i])
        pas[i] = False

    math = sorted(math)
    eng = sorted(eng)
    sum = sorted(sum)

    pas = judge_pass(x, math, pas)
    pas = judge_pass(y, eng, pas)
    pas = judge_pass(z, sum, pas)

    for key in pas:
        if pas[key]: print(key + 1)


if __name__ == '__main__':
    main()