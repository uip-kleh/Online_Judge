n, p, q, r, s = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
b = a.dup
b[p-1...q] = a[r-1...s]
b[r-1...s] = a[p-1...q]
puts b.join(' ')
