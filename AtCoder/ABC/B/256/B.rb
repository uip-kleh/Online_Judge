n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)

cnt = 0
for i in 0...n do
    pos = 0
    for j in i...n do
        pos += a[j]
        if pos >= 4 then
            cnt += 1
            break
        end
    end
end
p cnt 