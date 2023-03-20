h, w = gets.chomp.split.map(&:to_i)
a = Array.new
h.times do 
    a << gets.chomp.split.map(&:to_i)
end
ascii = ['.'] + [*('A'..'Z')]
ans = Array.new
a.each_with_index do |aa|
    s = String.new
    aa.each do |v|
        s += ascii[v]
    end
    ans << s
end
ans.each do |s|
    puts s
end
