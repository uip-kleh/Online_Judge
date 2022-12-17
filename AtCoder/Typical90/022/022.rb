a, b, c = gets.chomp.split.map(&:to_i)
gcd = a.gcd(b).gcd(c)
p a / gcd + b / gcd + c /gcd - 3