n, m = gets.chomp.split.map(&:to_i)
w = gets.chomp.split.map(&:to_i)
v = list(map(int, input().split()))
max_value = 0
for bits in range(1<<n):
    sum_w, sum_v = 0, 0
    for i in range(n):
        if bits & (1<<i): 
            sum_w += w[i]
            sum_v += v[i]
    if sum_w > m: continue
    max_value = max(max_value, sum_v)
print(max_value)
    