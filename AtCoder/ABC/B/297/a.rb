b = Array.new
r = Array.new
k = -1
gets.chomp.chars.each_with_index do |c, i|
  b << i % 2 if c == 'B'
  r << i if c == 'R'
  k = i if c == 'K'
end
puts (b.uniq.size == 2 and r[0] < k and k < r[1]) ? "Yes" : "No"
