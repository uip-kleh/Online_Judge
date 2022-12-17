n, k = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
points = Array.new
n.times do 
    points << gets.chomp.split.map(&:to_i)
end

hash = Hash.new(0)
# INITIALIZE
n.times do |i|
    if !a.include?(i+1) then hash[i] = (1 << 21)
    end
end
hash.each do |key, val|
    a.each do |i|
        len = Math.sqrt( (points[key][0] - points[i-1][0])**2 + (points[key][1] - points[i-1][1])**2 )
        hash[key] = [hash[key], len].min
    end
end
max_val = -(1 << 21)
hash.each do |key, val|
    min_val = [min_val, val].max
end
p max_val