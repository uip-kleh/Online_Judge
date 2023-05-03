n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
x = gets.chomp.to_i

asum = a.sum
cnt = x / asum * a.size
x %= asum
a.each do |v|
  break if x < 0
  x -= v
  cnt += 1
end
p cnt

