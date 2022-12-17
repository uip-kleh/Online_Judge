def is_standing(index, pos)
    pos[index].each do |val|
        return true if val == '1'
    end
    return false
end

s = gets.chomp
pos = Array.new(7){ Array.new }
index = 0
l = 3
cnt = 1
4.times do
    cnt.times do |i|
        pos[l + 2*i] << s[index]
        index += 1
    end
    l -= 1
    cnt += 1
end
is_split = false
[*0...7].combination(2).each do |c|
    break if s[0] == '1'
    l, r = c
    if is_standing(l, pos) and is_standing(r, pos)
        [*l..r].each do |mid|
            is_split = true if not is_standing(mid, pos)
        end
    end 
end
puts is_split ? "Yes" : "No"