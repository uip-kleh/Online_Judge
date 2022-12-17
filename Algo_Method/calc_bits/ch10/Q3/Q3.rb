n, m = gets.chomp.split.map(&:to_i)
w = gets.chomp.split.map(&:to_i)
v = gets.chomp.split.map(&:to_i)
max_value = 0
(1<<n).times do |bits|
    sum_w = 0
    sum_v = 0
    n.times do |i|
        if bits & (1<<i) != 0
            sum_w += w[i]
            sum_v += v[i]
        end
    end
    next if sum_w > m
    max_value = [max_value, sum_v].max
end
p max_value