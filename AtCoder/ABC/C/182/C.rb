s = gets.chomp.chars.map(&:to_i)
len = s.size
min_delete = (1 << 63)
len.times do |i|
    s.combination(len - i).each do |comb|
        n = comb.to_a.join.to_i
        min_delete = [min_delete, i].min if n % 3 == 0
    end
end
p min_delete == (1 << 63) ? -1 : min_delete