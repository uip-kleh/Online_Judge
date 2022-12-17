n, k = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
b = gets.chomp.split.map(&:to_i)

b.each_with_index do |val, i|
    a[i] -= val
    a[i] = a[i].abs
end
if a.sum > k 
    puts "No"
    return 
end

puts (a.sum - k) % 2 == 0 ? "Yes" : "No"