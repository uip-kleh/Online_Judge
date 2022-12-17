v, e, r = gets.chomp.split.map(&:to_i)
g = Array.new(v){ Array.new }
checked = Hash.new(0)
weight = Hash.new(0)
e.times do 
    s, t, d = gets.chomp.split.map(&:to_i)
    g[s] << t
    weight[[s, t]] = d
end

que = Array.new
que.push r
checked[r] = 0
while not que.empty? do
    node = que.shift    
    g[node].each do |new_node|
        next if not weight.has_key?([node, new_node])
        if checked.has_key?(new_node)
            # can find
            if checked[new_node] > checked[node] + weight[[node, new_node]]
                checked[new_node] = checked[node] + weight[[node, new_node]]
                que.push new_node
            end
        else
            # cannot find
            checked[new_node] = checked[node] + weight[[node, new_node]]
            que.push new_node
        end
    end
end

v.times do |i|
    if checked.has_key?(i)
        p checked[i]
    else 
        puts "INF"
    end
end
