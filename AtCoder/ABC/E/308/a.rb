def dp_cnt(s, t)
  # puts "#{s} #{t}"
  slen = s.length
  tlen = t.length
  dp = Array.new(tlen+1) { Array.new(slen+1, 0) }

  (slen+1).times do |i|
    dp[0][i] = 1
  end

  tlen.times do |i|
    slen.times do |j|
      dp[i+1][j+1] += dp[i+1][j]
      if t[i] == s[j] and dp[i][j] != 0
        dp[i+1][j+1] += dp[i][j]
      end

    end
  end

  # DISP DP
  # dp.each do |d|
    # p d
  # end

  return dp[-1][-1]
end

n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
s = gets.chomp

news = Array.new
s.chars.each_with_index do |c, i|
  newc = c + a[i].to_s
  news << newc
end

mi = ['M0', 'M1', 'M2']
ei = ['E0', 'E1', 'E2']
xi = ['X0', 'X1', 'X2']

ans = 0

3.times do |i|
  3.times do |j|
    3.times do |k|
      m = mi[i]
      e = ei[j]
      x = xi[k]
      mex = [0, 1, 2, 3]
      # p [m[-1], e[-1], x[-1]].sort.uniq
      [m[-1], e[-1], x[-1]].uniq.sort.map(&:to_i).each do |v|
        mex.delete(v)
      end
      score = mex[0]
      next if score == 0
      # p mex
      # p score
      ans += dp_cnt(news, [m, e, x]) * score
    end
  end
end

p ans

