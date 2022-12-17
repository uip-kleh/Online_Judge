n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i).sort
q = gets.chomp.to_i
q.times do 
    b = gets.to_i
    i = a.bsearch_index {|x| x >= b } || n-1
    puts [(a[i]-b).abs, (a[i-1]-b).abs].min
end