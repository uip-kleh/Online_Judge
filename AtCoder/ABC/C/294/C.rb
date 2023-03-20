n, m = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
b = gets.chomp.split.map(&:to_i)

c = (a + b).sort
aans = Array.new
a.each do |v|
    aans << c.bsearch_index{|val| val >= v} + 1
end
bans = Array.new
b.each do |v|
    bans << c.bsearch_index{|val| val >= v} + 1
end
puts aans.join ' '
puts bans.join ' '