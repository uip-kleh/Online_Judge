n, a, b = gets.chomp.split.map(&:to_i)

i = n / a
asum = a * (1 + i) * i / 2

i = n / b
bsum = b * (1 + i) * i / 2

i = n / (a * b / a.gcd(b))
absum = a * b / a.gcd(b) * (1 + i) * i / 2

p n * (1 + n) / 2 - asum - bsum + absum