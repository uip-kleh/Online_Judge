n, x = gets.chomp.split.map(&:to_i)
puts ((n >> x) & 1) == 1 ? "Yes" : "No" 