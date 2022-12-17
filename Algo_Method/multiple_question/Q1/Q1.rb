sa, ta = gets.chomp.split.map(&:to_i)
sb, tb = gets.chomp.split.map(&:to_i)
p [[ta, tb].min - [sa, sb].max, 0].max