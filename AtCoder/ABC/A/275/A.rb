n = gets.chomp.to_i
h = gets.chomp.split.map(&:to_i)
h.each_with_index do |v, i|
    p i + 1if h.max == v
end