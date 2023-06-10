# TLE

def calc_prime(n)
  isprime = Array.new(n, true)
  isprime[0] = isprime[1] = false
  n.times do |i|
    next if not isprime[i]
    j = i * 2
    while j < n do
      isprime[j] = false
      j += i
    end
  end
  return isprime
end

MAX = 3 * 10 ** 5 + 5
n = gets.chomp.to_i
isprime = calc_prime(MAX)
prime_num = Array.new
MAX.times do |i| prime_num << i if isprime[i]
end

ans = 0
m = prime_num.size
for i in 0...m do
  break if prime_num[i] * prime_num[i] > n
  for j in i+1...m do
    break if prime_num[i] * prime_num[i] * prime_num[j] > n
    for k in j+1...m do
      break if prime_num[i] * prime_num[i] * prime_num[j] * prime_num[k] > n or prime_num[i] * prime_num[i] * prime_num[j] * prime_num[k] * prime_num[k] > n
      ans += 1
    end
  end
end
p ans
