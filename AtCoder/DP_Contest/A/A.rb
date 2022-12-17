n = gets.chomp.to_i
h = gets.chomp.split.map(&:to_i)

dp = Array.new(n, 0)
dp[1] = (h[0] - h[1]).abs

for i in 2...n do
    dp[i] = [dp[i-1] + (h[i] - h[i-1]).abs, dp[i-2] + (h[i] - h[i-2]).abs].min  
end
p dp[n-1]