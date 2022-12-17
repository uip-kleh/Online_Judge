n = gets.chomp.to_i
hash = Hash.new(0)
hash[0] = true
d = 1
n.to_s(2).reverse.chars.each do |c|
    new_hash = Hash.new(0)
    if c.to_i == 0
        d *= 2
        next
    end
    hash.each do |key, val|
        new_hash[key] = true
        new_hash[key + c.to_i * d] = true
    end
    hash = new_hash
    d *= 2 
end
hash.sort.each do |key, val|
    p key
end
