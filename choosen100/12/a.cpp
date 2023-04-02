#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
#define SIZE 2e5
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

bool is_prime(ll x){
    if(x < 2) return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(ll i=0; i<x; i++) if(x%i == 0) return 0;
    return 0;
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

struct UnionFind {
    iv par, rank, siz;
    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}
    int root(int x){
        if(par.at(x) == -1) return x;
        else return par.at(x) = root(par.at(x));
    }
    bool is_same(int x, int y){
        return root(x) == root(y);
    }
    bool unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return false;
        if(rank.at(rx) < rank.at(ry)) swap(rx, ry);
        par.at(ry) = rx;
        if(rank.at(rx) == rank.at(ry)) rank.at(rx)++;
        siz.at(rx) += siz.at(ry);
        return true;
    }
    int group(){
        int cnt = 0;
        for(auto v: par) if(v == -1) cnt++;
        return cnt;
    }
};

int main(){
    int n, m; cin >> n >> m;
    iv x(m), y(m);
    iv z(n);
    rep(i, n) z.at(i) += (1<<i);
    rep(i, m){
        int x, y; cin >> x >> y, --x, --y;
        z.at(x) += (1<<y);
        z.at(y) += (1<<x);
    }
    // rep(i, n){
    //     cout << i << ':' << z.at(i) << endl;
    // }
    ll ans = 0;
    for(int bits=0; bits<(1<<n); bits++){
        // cout << bits << ":";
        set<int> st;
        bool b = true;
        rep(i, n){
            if(bits & (1<<i)){
                // cout << i << "=>";
                rep(j, n){
                    // if(bits & (1 << j))
                    if(!(z.at(j) & (1<<i)) and bits & (1 << j)) b = false;
                }
            }
        }
        // cout << endl;
        if(b){
            // cout << bits << endl;
            ll cnt = 0;
            rep(i, n){
                if(bits & (1<<i)) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}
