n, k, q = gets.chomp.split.map(&:to_i)
hash = Hash.new(0)
gets.chomp.split.map(&:to_i).each_with_index do |val, index| 
    hash[index + 1] = val
end
gets.chomp.split.map(&:to_i).each do |l|
    if hash[l] != n then
        next_to = false
        hash.each do |key, val|
            next_to = true if val == hash[l] + 1
        end
        hash[l] += 1 if !next_to
    end
end
cnt = 1
hash.each do |key, val|
    if cnt == k then p val
    else print "#{val} "
    end
    cnt += 1
end