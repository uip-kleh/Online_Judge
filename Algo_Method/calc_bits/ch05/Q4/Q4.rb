n, s = gets.chomp.split.map(&:to_i)
gets.chomp.to_i.times do 
    c, x = gets.chomp.split.map(&:to_i)
    if c == 0
        s ^= (1 << x)
    else
        puts (1 & (s >> x)) == 1 ? "on" : "off"
    end
end