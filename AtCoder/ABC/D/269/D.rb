def search(point, checked)
    # BASECASE
    if checked.has_key?(point)
        return checked if checked[point] 
    end

    # STEP
    checked[point] = true
    [*-1..1].repeated_permutation(2).each do |rperm|
        rperm = rperm.to_a
        next if rperm.sum == 0
        new_point = [point[0] + rperm[0], point[1] + rperm[1]]
        next if not checked.has_key?(new_point)
        checked = search(new_point, checked)
    end

    return checked
end

# INITIALIZE
checked = Hash.new(0)

# INPUT
n = gets.chomp.to_i
n.times do
    x, y = gets.chomp.split.map(&:to_i)
    checked[[x, y]] = false
end

cnt = 0
checked.each do |key, val|
    if not val
        #p checked
        checked = search(key, checked)
        cnt += 1
    end
end
p cnt