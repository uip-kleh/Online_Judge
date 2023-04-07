#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define SIZE 2e5
#define INF 1e9
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

struct edge {
    int from, to, length;
};

int main(){
    int n, m; cin >> n >> m;
    vector<edge> graph_edge(m);
    rep(i, m){
        int u, v, w; cin >> u >> v >> w;
        graph_edge.at(i) = {u, v, w};
    }

    vector<vector<ll>> dist_step(n, vector<ll>(n));
    rep(i, n){
        if(i == 0){
            dist_step.at(0).at(0) = 0;
            continue;
        }
        dist_step.at(i) = dist_step.at(i-1);
        rep(j, m){
            auto nv = graph_edge.at(j);
            dist_step.at(i).at(nv.to) = min(dist_step.at(i).at(nv.to), dist_step.at(i).at(nv.from) + nv.length);
        }
    }
    cout << (dist_step.at(n-2) != dist_step.at(n-1) ? "Yes" : "No") << endl;
}
