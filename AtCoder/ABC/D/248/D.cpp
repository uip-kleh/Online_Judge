#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<int> a(n); for(int i=0; i<n; i++) cin >> a.at(i);
    int q; cin >> q;
    vector<vector<int>> dp(n+1);
    for(int i=0; i<n; i++){
        dp.at(a.at(i)).push_back(i+1);
    }
    while(q--){
        int l, r, x; cin >> l >> r >> x;
        auto liter = lower_bound(dp.at(x).begin(), dp.at(x).end(), l);
        auto riter = lower_bound(dp.at(x).begin(), dp.at(x).end(), r+1);
        cout << distance(liter, riter) << endl;
    }
}