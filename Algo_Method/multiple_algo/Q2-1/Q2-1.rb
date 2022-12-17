def f(x) return x * (x * (x + 1) + 2) + 3
end 

# INPUT
n = gets.chomp.to_i

l = -1
r = 101
while r - l > 0.001 do
    mid = (l + r) / 2.0
    if f(mid) > n
        r = mid
    else
        l = mid
    end
end
p l