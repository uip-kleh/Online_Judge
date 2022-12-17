def calc_divisors(n):
    res = []
    i = 1
    while i * i <= n:
        if n % i == 0: 
            res.append(i)
            if n != i * i: res.append(n / i)
        i += 1
    return res

n = int(input())
a = list(map(int, input().split()))
dic = {}
for key in a:
    if not key in dic: dic[key] = 0
    dic[key] += 1

cnt = 0
for ai in dic.keys():
    for aj in calc_divisors(ai):
        ak = ai / aj
        if aj in dic and ak in dic: cnt += dic[ai] * dic[aj] * dic[ak]
print(cnt)

