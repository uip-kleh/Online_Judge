cnt = 0
s = gets.chomp
if s[0..1] == 'Mo'
    cnt = 5
elsif s[0..1] == 'Tu'
    cnt = 4
elsif s[0..1] == 'We'
    cnt = 3
elsif s[0..1] == 'Th'
    cnt = 2
elsif s[0..1] == 'Fr'
    cnt = 1
end
p cnt
