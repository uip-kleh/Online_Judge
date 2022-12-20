n, m = gets.chomp.split.map(&:to_i)
bits = Array.new
n.times do
    bit = 0
    gets.chomp.chars.each_with_index do |c, i|
        if c == 'o'
            bit += (1 << i)
        end
    end
    bits << bit
end
cnt = 0
bits.combination(2).each do |c|
    c = c.to_a
    cnt += 1 if (c[0] | c[1]) == (1 << m) - 1
end
p cnt