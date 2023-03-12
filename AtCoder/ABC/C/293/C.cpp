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

int h, w;
vector<bv> checked(11, bv(11, false));
ivv a(11, iv(11));
ll ans = 0;

void dfs(int x, int y, set<int> &happy){
    // basecase
    if(x < 0 or x>=w) return;
    if(y < 0 or y>=h) return;
    if(happy.find(a.at(y).at(x)) != happy.end()) return;
    //if(checked.at(y).at(x)) return;

    // step
    checked.at(y).at(x) = true;
    happy.insert(a.at(y).at(x));
    if(x == w-1 and y == h-1) if(happy.size() == h + w - 1) ans++;
    dfs(x+1, y, happy);
    dfs(x, y+1, happy);
    happy.erase(a.at(y).at(x));
}

int main(){
    cin >> h >> w;
    rep(i, h){
        rep(j, w) cin >> a.at(i).at(j);
    }

    set<int> happy;
    dfs(0, 0, happy);
    cout << ans << endl;
}
