n, k = gets.chomp.split.map(&:to_i)
vec = gets.chomp.split.map(&:to_i)

flat_vec = Array.new
vvec = Array.new(k) { Array.new }
vec.each_with_index do |v, i|
    vvec[i%k] << v
end
for i in 0...k do
    vvec[i].sort!
end
for i in 0...n do 
    flat_vec << vvec[i%k][i/k] 
end
puts flat_vec == vec.sort ? "Yes" : "No"