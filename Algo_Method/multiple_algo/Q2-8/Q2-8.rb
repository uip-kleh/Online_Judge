def f(x, len)
    cnt = 0
    len.each do |l|
        cnt += (l / x).to_i
    end
    return cnt 
end
n, k = gets.chomp.split.map(&:to_i)
len = gets.chomp.split.map(&:to_i)

l = 0
r = 2e5
while r - l > 1e-8 do
    mid = (l + r) / 2.0
    if f(mid, len) >= k
        l = mid
    else 
        r = mid
    end
end
p l