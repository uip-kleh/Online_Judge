h1, w1 = gets.chomp.split.map(&:to_i)
a = Array.new
h1.times do a << gets.chomp.split.map(&:to_i)
end
h2, w2 = gets.chomp.split.map(&:to_i)
b = Array.new
h2.times do b << gets.chomp.split.map(&:to_i)
end 

can_make = false

h_size = h1 - h2
w_size = w1 - w2
[*0...h1].combination(h_size).each do |h_vec|
    [*0...w1].combination(w_size).each do |w_vec|
        h_vec = h_vec.to_a
        w_vec = w_vec.to_a
        ans = Array.new
        for i in 0...h1 do
            p_ans = Array.new
            for j in 0...w1 do
                next if h_vec.include?(i) || w_vec.include?(j)
                p_ans << a[i][j]
            end
            ans << p_ans if !p_ans.empty?
        end
        can_make = true if ans == b
    end
end

puts can_make ? "Yes" : "No"