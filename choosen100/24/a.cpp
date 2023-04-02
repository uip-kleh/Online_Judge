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

ll t = 0;
iv start(SIZE), fin(SIZE);
bv checked(SIZE, false);
ivv g(SIZE);
void dfs(int node){
    if(checked.at(node)) return;

    start.at(node) = ++t;
    checked.at(node) = true;
    for(auto new_node: g.at(node)){
        dfs(new_node);
    }
    fin.at(node) = ++t;
}

int main(){
    int n; cin >> n;
    rep(i, n){
        int u, k; cin >> u >> k, --u;
        while(k--){
            int v; cin >> v, --v;
            g.at(u).push_back(v);
            // g.at(v).push_back(u);
        }
    }
    rep(i, n){
        sort(all(g.at(i)));
    }

    rep(i, n){
        if(checked.at(i)) continue;
        dfs(i);
    }
    rep(i, n){
        cout << i+1 << ' ' << start.at(i) << ' ' << fin.at(i) << endl;
    }
}
