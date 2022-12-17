n, m, x, t, d = gets.chomp.split.map(&:to_i)
p m >= x ? t : t - (x - m) * d