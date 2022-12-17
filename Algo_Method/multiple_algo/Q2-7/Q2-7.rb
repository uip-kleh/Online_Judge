def f(x) return x * (x + 1) / 2
end

n = gets.chomp.to_i
gets.chomp.split.map(&:to_i).each do |val|
    l = -1
    r = 2 * 10 ** 9
    while l != r do
        mid = (l + r) / 2
        if f(mid) >= val
            r = mid
        else 
            l = mid + 1
        end
    end
    p l
end
