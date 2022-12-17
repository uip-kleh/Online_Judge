#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int len = s.length(), max_bit = 0;

    for(int bit=0; bit<(1<<len); bit++){
        int cnt_bit = 0;
        ll n = 0;
        for(int i=0; i<len; i++){
            if(bit & (1<<i)){
                n = n * 10 + s.at(i) - '0';
                cnt_bit++;
            }
        }
        if(n % 3 == 0){
            max_bit = max(max_bit, cnt_bit);
        }
    }
    cout << (max_bit == 0 ? -1 : len - max_bit) << endl;
}