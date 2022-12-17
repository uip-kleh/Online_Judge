n = gets.chomp.to_i
array = Array.new
n.times do 
    s, t = gets.chomp.split
    array << [t.to_i, s]
end
puts array.sort[-2][-1]