n, k = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i).sort

cnt = 0
a.each do |val| cnt += a.size - (a.bsearch_index{|v| v >= k - val} || n) 
end
p cnt