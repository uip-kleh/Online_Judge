n = gets.chomp.to_i
s = gets.chomp.split.map(&:to_i)
t = gets.chomp.split.map(&:to_i)
(2*n).times do |i| t[(i+1) % n] = [t[(i+1) % n], t[i % n] + s[i % n]].min end
puts t.join "\n"
