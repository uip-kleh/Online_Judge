def analy_str(str):
    vec = list()
    cnt = 0
    pre_c = str[0]
    for c in str:
        if pre_c == c: cnt += 1
        else:
            vec.append([pre_c, cnt])
            pre_c = c
            cnt = 1
    #print(vec)
    return vec

def main():
    s = input() + ' '
    t = input() + ' '
    cnt_s = analy_str(s)
    cnt_t = analy_str(t)
    can_make = True

    if len(cnt_s) != len(cnt_t): can_make = False
    else:
        for i in range(len(cnt_s)):
            if cnt_s[i][0] != cnt_t[i][0]: can_make = False
            if cnt_s[i][1] == 1 and cnt_s[i][1] != cnt_t[i][1]: can_make = False
            if cnt_s[i][1] > 1 and cnt_s[i][1] > cnt_t[i][1]: can_make = False
    print("Yes") if can_make else print("No")

if __name__ == '__main__':
    main()