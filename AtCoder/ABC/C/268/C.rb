n = gets.chomp.to_i
hash = Hash.new(0)
gets.chomp.split.map(&:to_i).each_with_index do |p, i|
    key = i - p
    3.times do
        key += 1
        key %= n
        hash[key] += 1
    end
end
ans = 0
hash.each do |key, val|
    ans = [ans, val].max
end
p ans
