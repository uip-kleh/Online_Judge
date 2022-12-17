x, y, z = gets.chomp.split.map(&:to_i)
if x * y < 0 
    p x.abs
else
    if x > 0
        if x < y
            p x.abs
        else
            if z < y
                p z.abs + (y - z).abs + (x - y).abs
            else
                p -1
            end 
        end
    else
        if x > y
            p x.abs
        else
            if y < z
                p z.abs + (y - z).abs + (x - y).abs
            else
                p -1
            end
        end
    end
end