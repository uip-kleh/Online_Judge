n, x = gets.chomp.split.map(&:to_i)
s = String.new
for c in 'A'..'Z' do
    n.times do s += c end
end
puts s[x - 1]