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
    ll l, n1, n2; cin >> l >> n1 >> n2;
    map<ll, map<ll, ll>> imos;
    ll len = 0;
    rep(i, n1){
        ll v, l; cin >> v >> l;
        imos[v][len]++;
        len += l;
        imos[v][len]--;
    }
    len = 0;
    rep(i, n2){
        ll v, l; cin >> v >> l;
        imos[v][len]++;
        len += l;
        imos[v][len]--;
    }
    ll cnt = 0, prev = 0, sum = 0;;
    for(auto mp: imos){
        //cout << mp.first << ':' << endl;
        for(auto iter: mp.second){
            if(sum == 2){
                cnt += (iter.first - prev);
            }
            sum += iter.second;
            if(sum == 2) prev = iter.first;
        }
    }
    cout << cnt << endl;
}
