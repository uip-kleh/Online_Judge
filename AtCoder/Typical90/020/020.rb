a, b, c = gets.chomp.split.map(&:to_i)
puts a < c ** b ? "Yes" : "No"