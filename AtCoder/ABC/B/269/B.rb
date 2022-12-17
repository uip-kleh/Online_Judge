start = Array.new
goal = Array.new
10.times do |i|
    s = gets.chomp
    s.chars.each_with_index do |c, j|
        if c == '#'
            start = [i+1, j+1] if start.empty?
            goal = [i+1, j+1] 
        end
    end
end
puts "#{start[0]} #{goal[0]}\n#{start[-1]} #{goal[-1]}"