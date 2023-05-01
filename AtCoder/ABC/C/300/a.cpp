#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define SIZE 2e5
#define INF 2e18
constexpr long long MOD = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef vector<ll> iv;
typedef vector<bool> bv;
typedef pair<ll, ll> ip;
typedef vector<ip> pv;
typedef vector<iv> ivv;
ll gcd(ll a, ll b){
    return b ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll digsum(ll n){
    ll res = 0;
    while(n > 0){
        res += n%10;
        n /= 10;
    }
    return res;
}

ll pow(ll x, ll n){
    ll ans = 1;
    while(n){
        if(n % 2) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}
iv dx = {-1, -1, 1, 1};
iv dy = {-1, 1, -1, 1};

struct edge {
    int from, to, length;
};

int main(){
    int h, w; cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c.at(i);
    int n = min(h, w);
    iv ans(n, 0);

    rep(i, h){
        rep(j, w){
            if(c.at(i).at(j) == '.') continue;
            ll size = -1;
            // cout << i << ' ' << j << endl;
            rep(l, n){
                bool can_make = true;
                rep(k, 4){
                    int newi = i + dx.at(k) * (l+1);
                    int newj = j + dy.at(k) * (l+1);
                    // cout << newi << ' ' << newj << ' ';
                    if(newi < 0 or newi >= h) can_make = false;
                    if(newj < 0 or newj >= w) can_make = false;
                    if(!can_make) break;
                    // cout << c.at(newi).at(newj) << ' ';
                    if(can_make and c.at(newi).at(newj) != '#') can_make = false;
                }
                // cout << endl;
                if(can_make) size++;
                else{
                    break;
                }
            }
            if(size != -1){
                // cout << size << endl;
                ans.at(size)++;
            }
        }
    }
    for(auto v: ans) cout << v << ' ';
    cout << endl;
}
