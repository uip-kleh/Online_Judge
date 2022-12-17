n = gets.chomp.to_i
return if n.odd?
ans = Array.new
[0, 1].repeated_permutation(n).each do |perm|
    cnt = 0
    is_correct = true
    perm.to_a.each do |val|
        cnt += (val == 0 ? 1 : -1)
        is_correct = false if cnt < 0 
    end
    if is_correct and cnt == 0
        s = String.new
        perm.each do |val|
        s += (val == 0 ? '(' : ')')
        end
        ans << s
    end
end
ans.sort.each do |s|
    puts s
end