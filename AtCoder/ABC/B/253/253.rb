h, w = gets.chomp.split.map(&:to_i)
vec = Array.new
pos = Array.new
h.times do
    vec << gets.chomp
end
vec.each_with_index do |str, j|
    str.chars.each_with_index do |c, i|
        if c == 'o' then pos << [i, j]
        end
    end
end
p (pos[0][0] - pos[-1][0]).abs + (pos[0][-1] - pos[-1][-1]).abs