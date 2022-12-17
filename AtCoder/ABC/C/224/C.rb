# 面積使え！
def grad(p1, p2)
    return (p1[1] - p2[1] ) / (p1[0] - p2[0])
end

n = gets.chomp.to_i
cnt = 0
points = Array.new
n.times do
    points << gets.chomp.split.map(&:to_i)
end

points.combination(3).each do |p_points|
    p1, p2, p3 = p_points
    cnt += 1 if (p2[0] - p1[0]) * (p3[1] - p1[1]) != (p3[0] - p1[0]) * (p2[1] - p1[1]) 
end
p cnt