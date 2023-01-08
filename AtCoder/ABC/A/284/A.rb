n = gets.chomp.to_i
a = Array.new
n.times do a << gets.chomp 
end
a.reverse.each do |s| puts s
end