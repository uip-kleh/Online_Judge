s, t = gets.chomp.split.map(&:to_i)
cnt = 0
[*0..s].repeated_permutation(3).each do |perm|
  perm = perm.to_a
  if perm.sum <= s and perm[0] * perm[1] * perm[2] <= t
    cnt += 1
  end
end
p cnt
