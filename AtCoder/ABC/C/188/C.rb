n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
hash = Hash.new(0)
a.each_with_index do |val, i|
    hash[val] = i + 1
end
while a.size != 2 do
    new_a = Array.new
    (a.size / 2).times do |i|
        new_a << [a[2 * i], a[2 * i + 1]].max
    end
    a = new_a
end
p hash[a.min]