n, k = gets.chomp.split.map(&:to_i)
p = Array.new
n.times do |i| 
    p << [-gets.chomp.split.map(&:to_i).sum, i]
end

p.sort!

clear_score = p[k - 1][0].abs - 300
pass = Array.new(n, false)
p.each do |val, i|
    pass[i] = true if val.abs >= clear_score
end

for i in 0...n do
    puts pass[i] ? "Yes" : "No"
end