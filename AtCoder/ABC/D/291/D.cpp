#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
//#define SIZE
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
    ll res=1; while(n--) res *= x;
    return res;
}

struct UnionFind{
    iv par, rank, siz, min_node;
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
        if(is_same(x, y)) return false;
        if(siz.at(rx) < siz.at(ry)) swap(rx, ry);
        par.at(ry) = rx;
        if(rank.at(rx) == rank.at(ry)) rank.at(rx) += 1;
        siz.at(rx) += siz.at(ry);
        return true;
    }
};

const int MOD = 998244353;

int main(){
    int n; cin >> n;
    iv a(n), b(n);
    rep(i, n){
        cin >> a.at(i) >> b.at(i);
    }
    vector<int> dp1(n+1), dp2(n+1);
    dp1.at(0) = 1; dp2.at(0) = 1;
    rep(i, n-1){
        if(a.at(i+1) != a.at(i) and a.at(i+1) != b.at(i)){
            dp1.at(i+1) = dp1.at(i) + dp2.at(i);
        }
        if(a.at(i+1) != a.at(i) and a.at(i+1) == b.at(i)){
            dp1.at(i+1) = dp1.at(i);
        }
        if(a.at(i+1) == a.at(i) and a.at(i+1) != b.at(i)){
            dp1.at(i+1) = dp2.at(i);
        }
        if(a.at(i+1) == a.at(i) and a.at(i+1) == b.at(i)){
            dp1.at(i+1) = 0;
        }
        dp1.at(i+1) %= MOD;

        if(b.at(i+1) != a.at(i) and b.at(i+1) != b.at(i)){
            dp2.at(i+1) = dp1.at(i) + dp2.at(i);
        }
        if(b.at(i+1) != a.at(i) and b.at(i+1) == b.at(i)){
            dp2.at(i+1) = dp1.at(i);
        }
        if(b.at(i+1) == a.at(i) and b.at(i+1) != b.at(i)){
            dp2.at(i+1) = dp2.at(i);
        }
        if(b.at(i+1) == a.at(i) and b.at(i+1) == b.at(i)){
            dp2.at(i+1) = 0;
        }
        dp2.at(i+1) %= MOD;
    }
    // for(auto v: dp1) cout << v << ' ';
    // cout << endl;
    // for(auto v: dp2) cout << v << ' '; 
    // cout << endl;
    cout << (dp2.at(n-1) + dp1.at(n-1)) % MOD << endl;
}
