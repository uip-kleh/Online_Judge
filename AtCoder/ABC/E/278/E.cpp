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

int main(){
    int n; cin >> n;
    map<int, ll> mp;
    ll pre = 0;
    rep(i, n){
        int a; cin >> a;
        mp[i+1] = a; 
    }
    int q; cin >> q;
    while(q--){
        int c; cin >> c;
        if(c == 1){
            int x; cin >> x;
            pre = x;
            mp.clear();
        }
        if(c == 2){
            int i, x; cin >> i >> x;
            mp[i] += x;
        }
        if(c == 3){
            int i; cin >> i;
            cout << (mp.find(i) == mp.end() ? pre : pre + mp[i]) << endl;
        }
    }
}
