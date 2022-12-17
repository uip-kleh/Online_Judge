h, w, n = gets.chomp.split.map(&:to_i)
ha = Array.new
wa = Array.new
n.times do
    a, b = gets.chomp.split.map(&:to_i)
    ha << a
    wa << b
end

new_h = Hash.new(0)
new_w = Hash.new(0)
cnt = 1
ha.sort.uniq.each do |val|
    new_h[val] = cnt
    cnt += 1
end
cnt = 1
wa.sort.uniq.each do |val|
    new_w[val] = cnt
    cnt += 1
end

ha.each_with_index do |val, i|
    puts [new_h[val], new_w[wa[i]]].join(' ')
end