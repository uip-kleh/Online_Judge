#include<iostream>
#include<map>
using namespace std;

int main(){
    string s;
    cin >> s;
    map<char, int> m;
    for(auto c: s) m[c] = 0;
    for(auto c: s) m.at(c)++;
    string ans;
    for(auto iter: m){
        if(iter.second == 1){
            ans += iter.first;
            break;
        }
    }   
    if(ans.length() == 1) cout << ans << endl;
    else cout << -1 << endl;
}