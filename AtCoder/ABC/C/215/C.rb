s = gets.chomp
n = gets.chomp.to_i
names = Array.new
n.times do names << gets.chomp end
hash = Hash.new(0)
[*'a'..'z'].each_with_index do |c, i| hash[s[i]] = c
end
trans_names = Array.new
names.each_with_index do |s, i|
  trans_name = String.new
  s.each_char do |c|
    trans_name += hash[c]
  end
  trans_names << [trans_name, i]
end
trans_names.sort!
trans_names.each do |trans_name, i| puts names[i]
end

