n, p, q, r = gets.chomp.split.map(&:to_i);
hash = Hash.new(0)
crr = 0
hash[crr] = true
gets.chomp.split.map(&:to_i).each do |val|
    crr += val
    hash[crr] = true
end
can_make = false
hash.each do |key, val|
    can_make = true if hash.has_key?(key + p) and hash.has_key?(key + p + q) and hash.has_key?(key + p + q + r)
end

puts can_make ? "Yes" : "No"