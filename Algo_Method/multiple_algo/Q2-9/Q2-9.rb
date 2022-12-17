n, k = gets.chomp.split.map(&:to_i)
cnt = 0
[*1..n].each do |i|
    cnt += [(k / i).to_i, n].min
end
p cnt