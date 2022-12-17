hash = Hash.new(0)
certain_num = Array.new(0)
num = Array.new(0)
s = gets.chomp
s.chars.each_with_index do |c, i|
    certain_num << i if c == 'o'
    num << i if not c == 'x'
end
cnt = 4 - certain_num.size  
num.repeated_combination(cnt).each do |comb|
    comb = comb + certain_num
    comb.permutation.each do |perm|
        hash[perm.to_a.join] = true
    end
end
p hash.size 