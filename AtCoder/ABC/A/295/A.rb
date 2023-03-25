n = gets.chomp.to_i
a = gets.chomp.split
t = ["and", "not", "that", "the", "you"]
a.each do |s|
    if t.include?(s)
        puts "Yes"
        return 0
    end
end
puts "No"