a, b ,d = gets.chomp.split.map(&:to_i)
rad = Math::PI * d / 180
puts "#{a * Math.cos(rad) - b * Math.sin(rad)} #{a * Math.sin(rad) + b * Math.cos(rad)}"