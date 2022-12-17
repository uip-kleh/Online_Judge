#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    // INPUT
    int n, k, max_cnt = 0;
    cin >> n >> k;
    vector<string> ss(n);
    for(int i=0; i<n; i++) cin >> ss.at(i);

    for(int bit=0; bit<(1<<n); bit++){
        map<int, int> mp;
        for(int i=0; i<n; i++){
            if(bit & (1<<i)){
                for(auto c: ss.at(i)){
                    mp[c] += 1;
                }
            }
        }
        int cnt = 0;
        for(auto iter: mp){
            if(iter.second == k) cnt++;
        }   
        max_cnt = max(max_cnt, cnt);
    }
    cout << max_cnt << endl;
}