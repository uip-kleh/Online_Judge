n, s = gets.chomp.split.map(&:to_i)
q = gets.chomp.to_i
q.times do
    c, x = gets.chomp.split.map(&:to_i)
    if c == 0
        s = s | (1 << x)
    else
        puts (s & (1 << x)) == 0 ? "off" : "on"
    end
end