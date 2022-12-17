a, i = gets.chomp.split.map(&:to_i)
p a ^ (1 << i)