#include<iostream>
using namespace std;

int main(){
    int n, q, head = 0;
    cin >> n >> q;
    string s;
    cin >> s;
    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            head -= x;
            head %= n;
        }
        else{
            int index = (head + x - 1) % n;
            if(index < 0) index += n;
            cout << s.at(index) << endl;
        }
    }
}