import os

if __name__ == '__main__':
    num = int(input('Input the number of Contest!'))
    level = ['A', 'B', 'C', 'D']
    for l in level:
        dir = os.path.join(l, str(num))
        if not os.path.exists(dir): os.mkdir(dir)
        file = os.path.join(dir, l + '.cpp')
        os.system('touch ' + file)