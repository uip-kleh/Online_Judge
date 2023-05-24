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
    int n, m; cin >> n >> m;
    iv x(m); rep(i, m) cin >> x[i];

    iv dist;
    sort(all(x));
    rep(i, m-1){
        dist.push_back(abs(x[i] - x[i+1]));
    }
    sort(all(dist));
    ll ans = 0;
    rep(i, m-n) ans += dist[i];
    cout << ans << endl;
} 


