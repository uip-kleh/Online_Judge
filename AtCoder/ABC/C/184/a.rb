r1, c1 = gets.chomp.split.map(&:to_i)
r2, c2 = gets.chomp.split.map(&:to_i)

r2 -= r1
c2 -= c1

if r2 == 0 and c2 == 0
  p 0
  return
end

# puts "#{r2} #{c2}"
if r2.abs == c2.abs
  p 1
  return
end

vec = Hash.new(0)
vec[3] = [0]
vec[2] = [*-2..2]
vec[1] = [*-2..2]
vec[0] = [*-3..3]
vec[-1] = [*-2..2]
vec[-2] = [*-2..2]
vec[-3] = [0]

vec.each do |dx, dys|
  dys.each do |dy|
    if r2 == dx and c2 == dy
      p 1
      return
    end
    # puts "#{dx} #{dy}"
  end
end

vec.each do |dx, dys|
  dys.each do |dy|
    if (r2 - dx).abs == (c2 - dy).abs
      p 2
      return
    end
    # puts "#{dx} #{dy}"
  end
end

if r2 % 2 == c2 % 2
  p 2
  return
end

if r2.abs + c2.abs <= 6
  p 2
  return
end
p 3
