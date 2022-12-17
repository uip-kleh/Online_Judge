n, m = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i).sort
b = gets.chomp.split.map(&:to_i)
b.each do |val| p a.bsearch_index{|v| v > val} || n
end