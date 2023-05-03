import math
def isPrime(n: int):
    if n == 1: return False
    if n == 2: return True
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0: return False
    return True

n = int(input())
ans = 0
for _ in range(n):
    num = int(input())
    if(isPrime(num)): ans += 1
print(ans)
