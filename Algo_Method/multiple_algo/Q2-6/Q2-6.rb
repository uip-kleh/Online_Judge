n = gets.chomp.to_i
w = gets.chomp.split.map(&:to_i)
w_sort = w.sort
w.each do |val| p w_sort.bsearch_index{|v| v>=val}
end
