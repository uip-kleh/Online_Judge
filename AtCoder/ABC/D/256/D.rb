query = Array.new { Array.new(2) }
gets.chomp.to_i.times do
    l, r = gets.chomp.split.map(&:to_i)
    query << [l, 0]
    query << [r, 1]
end
query.sort!
cnt = 0
query.each do |vec|
    if vec[-1] == 0 then
        print "#{vec[0]} " if cnt == 0
        cnt += 1
    else
        cnt -= 1
        p vec[0] if cnt == 0
    end
end