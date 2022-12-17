direct = [-1, 0, 1].repeated_permutation(2).to_a
direct.delete([0, 0])

n = gets.chomp.to_i
array = Array.new
n.times do
    array << gets.chomp
end

max_val = -1
for i in 0...n do
    for j in 0...n do
        direct.each do |vec|
            s = [i, j].dup
            str = ""
            n.times do
                i += vec[0]
                j += vec[1]
                str += array[i%n][j%n]
            end
            max_val = [max_val, str.to_i].max
        end
    end
end
p max_val