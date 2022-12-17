
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

struct pair_hash{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const{
        std:size_t h1 = std::hash<T1>()(pair.fist);
        std::size_t h2 = std::hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};

int main(){
    int n; cin >> n;
    ivv g(n, iv(n, 0));
    rep(i, n){
        int u, k; cin >> u >> k, u--;
        rep(i, k){
            int v; cin >> v, v--;
            g.at(u).at(v) = 1;
        }
    }

    rep(i, n){
        rep(j, n){
            cout << g.at(i).at(j);
            cout << (j == n - 1 ? "\n" : " ");
        }
    }
}

