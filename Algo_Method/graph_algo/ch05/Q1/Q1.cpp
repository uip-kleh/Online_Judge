#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
#define SIZE 200000
using namespace std;
typedef long long ll;
typedef vector<ll> iv;
typedef vector<bool> bv;
typedef vector<ll> lv;
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

int n, m, s, t;
bool reached = false;
vector<bool> checked(SIZE, false);
ivv graph(SIZE);

void dfs(int node){
    if(checked.at(node)) return;
    if(node == t) reached = true;

    checked.at(node) = true;
    for(auto new_node: graph.at(node)){
        dfs(new_node);
    }
}

int main(){
    cin >> n >> m >> s >> t;
    rep(i, m){
        int u, v; cin >> u >> v;
        graph.at(u).push_back(v);
    }

    // DFS
    dfs(s);

    // DISPLAY 
    cout << (reached ? "Yes" : "No") << endl;
}