n = gets.chomp.to_i
flag = Array.new
30.times do |i|
    flag << i if (n & (1 << i)) != 0
end
p flag.size
puts flag.join ' '