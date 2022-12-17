n = gets.chomp.to_i
s = gets.chomp
t_s = s[n...2*n] + s[0...n]
q = gets.chomp.to_i
cnt = 0
current = s.dup
q.times do
    t, a, b = gets.chomp.split.map(&:to_i)
    if t == 1 then 
        if cnt % 2 == 0 then
            s[a-1], s[b-1] = s[b-1], s[a-1]
            t_s[a-1-n], t_s[b-1-n] = t_s[b-1-n], t_s[a-1-n]
        else 
            s[a-1-n], s[b-1-n] = s[b-1-n], s[a-1-n]
            t_s[a-1], t_s[b-1] = t_s[b-1], t_s[a-1]
        end
    elsif t == 2 then
        cnt += 1 
    end
end
puts cnt % 2 == 0 ? s : t_s