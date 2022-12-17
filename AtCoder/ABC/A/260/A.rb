s = gets.chomp
hash = Hash.new(0)
s.chars.uniq.each do |c| hash[c] = 0
end
s.chars.each do |c| hash[c] += 1
end
ans = ""
hash.each do |key, val|
    if val == 1 then
        ans = key
        break
    end
end
puts ans.size == 0 ? -1 : ans