import math

def main():
    a, b, d = map(int, input().split())
    rad = math.pi * d / 180
    print(str(a * math.cos(rad) - b * math.sin(rad)) + ' ' + str(a * math.sin(rad) + b * math.cos(rad)))

if __name__ == '__main__':
    main()