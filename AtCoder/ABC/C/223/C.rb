n = gets.chomp.to_i
t = 0
l = 0
arry_a = Array.new
arry_b = Array.new

n.times do 
    a, b = gets.chomp.split.map(&:to_i)
    arry_a << a
    arry_b << b
    t += a / b.to_f
end
t /= 2.0

for i in 0...n do
    time = arry_a[i] / arry_b[i].to_f
    if t > time then 
        l += arry_a[i]
        t -= time
    else 
        l += arry_b[i] * t
        break
    end
end
p l