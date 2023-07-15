gets
s, t = [], 0
gets.chomp.chars.each do |c|
  if c == ')' and t > 0
    while s.pop != '('
    end
    t -= 1
  else
    s.push c
    t += 1 if c == '('
  end
end

puts s.join
