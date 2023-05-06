s = gets.chomp.split('+')
ans = s.size
s.each do |c|
  if c.include?('*0') or c.include?('0*') or c == '0'
    ans -= 1
  end
end
p ans
