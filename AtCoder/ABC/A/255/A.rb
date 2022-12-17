r, c = gets.chomp.split.map(&:to_i)
a = Array.new
2.times do
    a << gets.chomp.split.map(&:to_i)
end
p a[r-1][c-1]