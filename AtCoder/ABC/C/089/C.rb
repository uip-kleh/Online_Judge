n = gets.chomp.to_i
initial = ['M', 'A', 'R', 'C', 'H']
hash = Hash.new(0)
initial.each do |c| hash[c] = 0
end
names = Array.new
n.times do 
    s = gets.chomp
    if initial.include?(s[0]) 
        names << s
        hash[s[0]] += 1
    end
end
#p names
#p hash
sum = 0
initial.combination(3).each do |comb|
    cnt = 1
    comb.to_a.each do |c|
        cnt *= hash[c]
    end
    sum += cnt
end
p sum