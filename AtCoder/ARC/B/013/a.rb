c = gets.chomp.to_i
w = Array.new
c.times do w << gets.chomp.split.map(&:to_i).sort
end

maxarry = Array.new(3, 0)
w.each do |v|
  3.times do |i|
    maxarry[i] = [maxarry[i], v[i]].max
  end
end

p maxarry[0] * maxarry[1] * maxarry[2]
