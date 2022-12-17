a = [1]
p a[0]
(gets.chomp.to_i-1).times do |i|
    buf = Array.new
    buf << 1
    i.times do |j|
       buf << a[j] + a[j+1] 
    end
    buf << 1
    a = buf
    for j in 0..i do
        print("#{a[j]} ")
    end
    p a[i+1]
end