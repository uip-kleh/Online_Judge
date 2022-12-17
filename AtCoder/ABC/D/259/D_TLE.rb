def distance(i, j, points)
    return (points[i][0] - points[j][0]) ** 2 + (points[i][1] - points[j][1]) ** 2
end

n = gets.chomp.to_i
sx, sy, tx, ty = gets.chomp.split.map(&:to_i)

points = Array.new
r = Array.new
n.times do
    x, y, z = gets.chomp.split.map(&:to_i)
    points << [x, y]
    r << z
end

$can_goal = false

def dfs(node, checked, g, goal)
    # basecase
    $can_goal = true if goal.include?(node)
    return if checked[node]

    # step
    checked[node] = true
    g[node].each do |new_node|
        dfs(new_node, checked, g, goal)
    end
end


g = Array.new(n) { Array.new }
for i in 0...n do
    for j in i+1...n do
        d = distance(i, j, points)
        if d > (r[i]+r[j]) ** 2 || d < (r[i]-r[j]) ** 2 then next
        else
            g[i] << j
            g[j] << i
        end
    end
end

start = Array.new
goal = Array.new
for i in 0...n do
    start_d = (sx - points[i][0]) ** 2 + (sy - points[i][1]) ** 2
    goal_d = (tx - points[i][0]) ** 2 + (ty - points[i][1]) ** 2
    start << i if start_d == r[i] ** 2
    goal << i if goal_d == r[i] ** 2
end

start.each do |s|
    checked = [false] * n
    dfs(s, checked, g, goal)
end

puts $can_goal ? "Yes" : "No"

=begin
# disp
puts "--- disp g ---"
g.each do |v|
    p v
end

puts "--- disp start ---"
p start
puts "--- disp goal ---"
p goal
=end