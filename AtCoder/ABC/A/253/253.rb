vec = gets.chomp.split.map(&:to_i)
puts vec[1] == vec.sort[1] ? "Yes" : "No"