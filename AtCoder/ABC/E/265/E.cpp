#include<iostream>
#include<vector>
#include<set>
#include<map>
#define MOD 998244353
using namespace std;
typedef long long ll;

int main(){
    // INPUT
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> dxy;
        // INPUT A B
    for(int i=0; i<3; i++){
        int x, y; 
        cin >> x >> y;
        dxy.push_back(make_pair(x, y));
    }
    set<pair<int, int>> s;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }

    // SET DP
    map<pair<ll, ll>, ll> dp;
    dp[make_pair(0, 0)] = 1;
    for(int i=0; i<n; i++){
        map<pair<ll, ll>, ll> new_dp;
        for(auto dp_iter: dp){
            for(auto dxy_iter: dxy){
                pair<ll, ll> new_key = make_pair((dp_iter.first.first + dxy_iter.first), (dp_iter.first.second + dxy_iter.second));
                if(s.find(new_key) == s.end()){
                    new_dp[new_key] += dp_iter.second;
                    new_dp[new_key] %= MOD;
                }
            }
        }
        dp = new_dp;
    }

    ll cnt = 0;
    for(auto iter: dp){
        cnt += iter.second;
        cnt %= MOD;
    }
    cout << cnt << endl;
}
