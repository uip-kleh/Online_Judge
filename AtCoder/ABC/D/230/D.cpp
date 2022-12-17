#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, d; cin >> n >> d;
    vector<pair<int, int>> rl;
    for(int i=0; i<n; i++){
        int l, r; cin >> l >> r;
        rl.push_back(make_pair(r, l));
    }
    sort(rl.begin(), rl.end());
    int cnt = 1, pre_r = 0;
    for(auto iter: rl){
        int r = iter.first, l = iter.second;
        if(pre_r == 0) pre_r = r;
        if(l - pre_r + 1 >= d and pre_r + d - 1 < l){
            pre_r = r;
            cnt++;
        }
    }
    cout << cnt << endl;
}