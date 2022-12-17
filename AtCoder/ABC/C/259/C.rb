def analy_str(str)
    vec = Array.new
    cnt = 0
    pre_c = str[0]
    str.chars.each do |c|
        if c == pre_c then cnt += 1
        else
            vec << [pre_c, cnt]
            pre_c = c
            cnt = 1
        end
    end
    #p vec
    return vec
end 

s = gets.chomp + ' '
t = gets.chomp + ' '

cnt_s = analy_str(s)
cnt_t = analy_str(t)

can_make = true
if cnt_s.size != cnt_t.size()  then can_make = false
else
    for i in 0...cnt_s.size() do
        can_make = false if cnt_s[i][0] != cnt_t[i][0]
        can_make = false if cnt_s[i][1] == 1 && cnt_s[i][1] != cnt_t[i][1]
        can_make = false if cnt_s[i][1] > 1 && cnt_s[i][1] > cnt_t[i][1]
    end
end
puts can_make ? "Yes" : "No"