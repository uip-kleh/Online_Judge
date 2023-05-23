#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
//#define SIZE
constexpr long long MOD = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef vector<ll> iv;
typedef vector<bool> bv;
typedef pair<ll, ll> ip;
typedef vector<ip> pv;
typedef vector<iv> ivv;

int main(){
    int n, q; cin >> n >> q;
    unordered_map<int, unordered_set<int>> mp;
    ll ans = n;
    while(q--){
        int c; cin >> c;
        if(c == 1){
            int u, v; cin >> u >> v;
            if(mp[u].empty()) ans--;
            if(mp[v].empty()) ans--;
            mp[u].insert(v);
            mp[v].insert(u);
        }
        if(c == 2){
            int v; cin >> v;
            if(mp[v].empty()) ans--;
            for(auto u: mp[v]){
                mp[u].erase(v);
                if(mp[u].size() == 0) ans++;
            }
            mp[v].clear();
            ans++;
        }
        cout << ans << endl;
    }
}
