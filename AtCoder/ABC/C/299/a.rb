gets
s = gets.chomp
if not s.include?('-') or not s.include?('o')
  p -1
  return
end
p s.split('-').sort[-1].size

