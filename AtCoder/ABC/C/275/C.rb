def len(p1, p2)
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
end

ss = Array.new
9.times do ss << gets.chomp
end
grid = Array.new
9.times do |i|
    9.times do |j|
        if ss[i][j] == '#'
            grid << [i, j]
        end
    end
end
cnt = 0
grid.combination(4).each do |comb|
    hash = Hash.new(0)
    p1, p2, p3, p4 = comb.to_a
    hash[len(p1, p2)] += 1
    hash[len(p1, p3)] += 1
    hash[len(p1, p4)] += 1
    hash[len(p2, p3)] += 1
    hash[len(p2, p4)] += 1
    hash[len(p3, p4)] += 1
    
    cnt += 1 if hash.size == 2
end
p cnt