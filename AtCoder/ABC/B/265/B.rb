n, m, t = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
hash = Hash.new(0)

m.times do
    x, y = gets.chomp.split.map(&:to_i)
    hash[x-2] = y
end

goal = true

a.each_with_index do |val, i|
    t -= val
    goal = false if t <= 0
    t += hash[i] if hash.has_key?(i)
end

puts goal ? "Yes" : "No"