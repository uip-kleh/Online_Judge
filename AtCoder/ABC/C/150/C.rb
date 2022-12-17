n = gets.chomp.to_i
p = gets.chomp.split.map(&:to_i)
q = gets.chomp.split.map(&:to_i)

a = Array.new
ans = Array.new

p.permutation.each do |perm|
    a << perm.to_a.join
end
a.sort.each_with_index do |s, i|
    ans << i if s == p.join or s == q.join
end
p ans.size == 1 ? 0 : (ans[0] - ans[1]).abs