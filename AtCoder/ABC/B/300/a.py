h, w = gets.chomp.split.map(&:to_i)
a = Array.new
b = Array.new
h.times do a << gets.chomp end
h.times do b << gets.chomp end

can_make = false
h.times do |s|
  w.times do |t|
    is_same = true
    h.times do |i|
      w.times do |j|
        is_same = false if b[i][j] != a[(i+s)%h][(j+t)% w]
      end
    end
    if is_same
      puts "Yes"
      return 0
    end
  end
end
puts "No"

