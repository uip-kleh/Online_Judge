n, d = gets.chomp.split.map(&:to_i)
t = gets.chomp.split.map(&:to_i)
(n-1).times do |i|
  if t[i+1] - t[i] <= d
     p t[i+1]
     return
  end
end
p -1
