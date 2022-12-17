def f(n, x)
    n += 1
    5.times do
        n = n * x + 1 
    end
    return n
end

n, m = gets.chomp.split.map(&:to_i)

l = -1
r = 101
while r - l > 0.0001 do
    mid = (l + r) / 2.0
    if f(n, mid) > m
        r = mid
    else
        l = mid
    end
end
p l