n = gets.chomp.to_i
student = Array.new(2){ Array.new }
csum = Array.new(2){ Array.new(1, 0) }
n.times do |i|
    c, p = gets.chomp.split.map(&:to_i)
    csum[c-1] << csum[c-1][-1] + p
    csum[c%2] << csum[c%2][-1] 
end

q = gets.chomp.to_i
q.times do 
    l, r = gets.chomp.split.map(&:to_i)
    puts "#{csum[0][r] - csum[0][l-1]} #{csum[1][r] - csum[1][l-1]}"
end
