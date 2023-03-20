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

void disp_dp(ivv &dp){
    for(iv p: dp){
        for(auto v: p) cout << v << ' ';
        cout << endl;
    }
}

int main(){
    int h, w, n; cin >> h >> w >> n;
    iv aa, bb;
    iv x, y;
    rep(i, n){
        int a, b; cin >> a >> b;
        aa.push_back(a);
        bb.push_back(b);
        x.push_back(a);
        y.push_back(b);
    }
    sort(all(x)); sort(all(y));
    x.erase(unique(all(x)), x.end());
    y.erase(unique(all(y)), y.end());
    rep(i, n){
        cout << lower_bound(all(x), aa.at(i)) - x.begin() + 1 << ' ' << lower_bound(all(y), bb.at(i)) - y.begin() + 1 << endl;
    }
}
