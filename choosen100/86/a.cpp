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
iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

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
    iv a(m), b(m);
    rep(i, m) cin >> a.at(i) >> b.at(i), --a.at(i), --b.at(i);
    ll cnt = 0;
    rep(i, m){
        UnionFind uf(n);
        rep(j, m){
            if(i == j) continue;
            uf.unite(a.at(j), b.at(j));
        }
        ll max_size = 0;
        for(auto size: uf.siz) max_size = max(max_size, size);
        // cout << max_size << endl;
        if(max_size != n) cnt++;
    }
    cout << cnt << endl;
}
