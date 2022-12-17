r, c = gets.chomp.split.map(&:to_i)

grid = Array.new    

mid_cnt = 15
side_s = String.new

8.times do |i|
    mid_c = i.even? ? "b" : "w"
    s = side_s + mid_c * mid_cnt + side_s.reverse 
    side_s += i.even? ? "b" : "w"
    mid_cnt -= 2
    grid << s
end

grid += grid[0..6].reverse

puts grid[r-1][c-1] == "b" ? "black" : "white"