n, s = gets.chomp.split.map(&:to_i)
history = Array.new
dp = Hash.new(0)
dp[0] = true
history << dp
ab = Array.new
n.times do
    a, b = gets.chomp.split.map(&:to_i)
    ab << [a, b]
    new_dp = Hash.new(0) 
    dp.each do |key, val|
        new_dp[key + a] = true
        new_dp[key + b] = true
    end
    dp = new_dp
    history << dp
end
puts dp.has_key?(s) ? "Yes" : "No"
return if not dp.has_key?(s) 
ans = String.new
ab.reverse.each_with_index do |(a, b), i|
    if history[n - i - 1].has_key?(s - a) or s - a == 0
        s -= a
        ans += 'H'
    else 
        s -= b
        ans += 'T'
    end
end
puts ans.reverse