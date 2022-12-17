n = gets.chomp.to_i % 100
puts n < 10 ? "0#{n}" : n 