n, k = gets.chomp.split.map(&:to_i)
ss = Array.new
n.times do
    ss << gets.chomp
end
max_cnt = 0
n.times do |i|
    ss.combination(i+1).each do |comb|
        hash = Hash.new(0)
        comb.to_a.each do |s|
            s.chars.each do |c|
                hash[c] += 1
            end
        end
        cnt = 0
        hash.each do |key, val|
            cnt += 1 if val == k
        end
        max_cnt = [max_cnt, cnt].max
    end
end
p max_cnt