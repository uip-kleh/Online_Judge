#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
#define SIZE 101
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

int t=1;
iv d(SIZE), f(SIZE);
bv checked(SIZE, false);

void dfs(int node, ivv &g){
    // basecase 
    if(checked.at(node)) return;

    // step
    checked.at(node) = true;
    d.at(node) = t;
    t++;
    for(auto new_node: g.at(node)){
        dfs(new_node, g);
    }
    f.at(node) = t;
    t++;
}

int main(){
    int n; cin >> n;
    ivv g(n+1);
    rep(i, n){
        int u, k; cin >> u >> k;
        rep(j, k){
            int v; cin >> v;
            g.at(u).push_back(v);
        }
    }

    for(int i=1; i<n+1; i++){
        if(checked.at(i)) continue;
        dfs(i, g);
    }

    for(int i=1; i<n+1; i++){
        cout << i << ' ' << d.at(i) << ' ' << f.at(i) << endl;
    }
}

