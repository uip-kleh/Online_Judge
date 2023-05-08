n, x = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
hash = Hash.new(0)
a.each do |v| hash[v] = true
end
a.each do |v|
  if hash.include?(v + x)
    puts "Yes"
    return
  end
end

puts "No"
