n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
hash = Hash.new(0)
hash[1] = 0
a.each_with_index do |val, i|
    hash[2 * (i + 1)] = hash[val] + 1
    hash[2 * (i + 1) + 1] = hash[val] + 1
end
[*1..(2*n + 1)].each do |i| p hash[i]
end 