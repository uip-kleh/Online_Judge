h, w = gets.chomp.split.map(&:to_i)
a = Array.new
h.times do
    a << gets.chomp.split.map(&:to_i)
end

hsum = Array.new
wsum = Array.new
a.each do |portion| hsum << portion.sum
end
a.transpose.each do |portion| wsum << portion.sum
end
for i in 0...h do
    for j in 0...w do
        print hsum[i] + wsum[j] - a[i][j]
        print j == w - 1 ? "\n" : " "
    end
end 
