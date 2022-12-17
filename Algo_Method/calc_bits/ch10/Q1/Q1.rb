n, x = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
sum = 0
n.times do |i| sum += a[i] if x & (1<<i) != 0
end
p sum