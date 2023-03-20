n = gets.chomp.to_i
ans = Array.new
gets.chomp.split.map(&:to_i).each do |v|
    ans << v if v.even?
end
puts ans.join ' '
