n = gets.chomp.to_i
w = Array.new
hash = Hash.new(0)
n.times do w << gets.chomp
end
w.each do |s| hash[s] = true
ends
if hash.size != n
  puts "No"
  retrun
end
(n-1).times do |i|
end
