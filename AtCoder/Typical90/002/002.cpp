#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> ans;
    if(n%2 == 1) return 0;
    for(int bit=0; bit<(1<<n); bit++){
        int cnt = 0;
        bool is_correct = true;
        for(int i=0; i<n; i++){
            if(bit & (1<<i)){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt < 0) is_correct = false;
        }
        if(is_correct && cnt == 0){
            string s;
            for(int i=0; i<n; i++){
                if(bit & (1<<i)){
                    s += '(';
                }
                else{
                    s += ')';
                }
            }
            ans.push_back(s);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto s: ans){
        cout << s << endl;  
    }
}