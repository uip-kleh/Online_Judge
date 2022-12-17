n, t = gets.chomp.split.map(&:to_i)
vec_t = gets.chomp.split.map(&:to_i)

time = 0
for i in 1...n do 
    time += [t, vec_t[i] - vec_t[i-1]].min
end
p time + t