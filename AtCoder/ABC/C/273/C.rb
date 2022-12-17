n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
hash = Hash.new(0)
a.each do |key| hash[key] += 1 end
uniq_a = a.uniq.sort
ans = [0] * n
uniq_a.each do |key|
    i = uniq_a.bsearch_index{|v| v >= key}
    ans[uniq_a.size - i - 1] = hash[key]
end
ans.each do |val| p val end