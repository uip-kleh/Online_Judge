$hash = Hash.new(0)

def f(n)
    return 1 if n == 0
    return $hash[n] if $hash.has_key?(n)

    val = f(n / 2) + f(n / 3)
    $hash[n] = val
    return val
end

n = gets.chomp.to_i
p f(n)