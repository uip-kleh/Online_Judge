n, q = gets.chomp.split.map(&:to_i)
a = Array.new
n.times do 
    a << gets.chomp.split.map(&:to_i)[1..]
end
q.times do
    s, t = gets.chomp.split.map(&:to_i) 
    p a[s-1][t-1]
end