def judge_pass(max_num, subject, pass)
    cnt = 0
    subject.each do |score, i|
        break if cnt == max_num
        if !pass[i] then
            pass[i] = true
            cnt += 1 
        end
    end

    return pass
end

n, x, y, z = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
b = gets.chomp.split.map(&:to_i)
math = Array.new
eng = Array.new
sum = Array.new
pass = Hash.new(0)

n.times do |i| 
    math << [-a[i], i]
    eng << [-b[i], i]
    sum << [-a[i]-b[i], i]
    pass[i] = false
end

math.sort!
eng.sort!
sum.sort!

pass = judge_pass(x, math, pass)
pass = judge_pass(y, eng, pass)
pass = judge_pass(z, sum, pass)

pass.each do |key, val| p key+1 if val
end