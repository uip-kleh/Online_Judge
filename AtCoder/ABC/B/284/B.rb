t = gets.chomp.to_i
t.times do 
    cnt = 0
    n = gets.chomp.to_i
    gets.chomp.split.map(&:to_i).each do |v|
        cnt += 1 if v.odd?
    end
    p cnt
end