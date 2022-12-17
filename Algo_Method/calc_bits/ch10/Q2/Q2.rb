n, v = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
can_make = false
(1<<n).times do |bits|
    sum = 0
    n.times do |i| sum += a[i] if bits & (1<<i) != 0
    end
    can_make = true if sum == v
end
puts can_make ? "Yes" : "No"