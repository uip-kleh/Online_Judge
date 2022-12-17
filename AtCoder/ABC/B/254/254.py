if __name__ == '__main__':
    vec = [1]
    
    n = int(input())
    print(1)

    for i in range(1, n):
        buf = []
        buf.append(1)
        for j in range(i-1):
            buf.append(vec[j] + vec[j+1])
        buf.append(1)
        vec = buf
        for j in range(i):
            print(str(vec[j]), end = " ")
        print(vec[i])