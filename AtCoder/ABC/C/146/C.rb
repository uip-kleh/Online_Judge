def need(n, a, b)
    return a * n + b * n.to_s.size
end

a, b, x = gets.chomp.split.map(&:to_i)
l = 0
r = 10**9 + 1
while r - l > 1 do
    mid = (l + r) / 2
    mid_val = need(mid, a, b)
    if mid_val > x
        r = mid
    else
        l = mid 
    end
    #puts "#{l} #{r}"
end

p l