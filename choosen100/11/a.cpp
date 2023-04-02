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

int main(){
    int n, m; cin >> n >> m;
    ivv s(m);
    rep(i, m){
        int k; cin >> k;
        while(k--){
            int a; cin >> a;
            s.at(i).push_back(a);
        }
    }
    iv p(m); rep(i, m) cin >> p.at(i);
    ll ans = 0;
    for(int bits=0; bits<(1<<n); bits++){
        iv swt(n);
        rep(i, n){
            if(bits & (1 << i)){
                swt.at(i)++;
            }
        }
        iv cnt(m);
        rep(i, m){
            for(auto v: s.at(i)){
                if(swt.at(v-1) == 1){
                    cnt.at(i)++;
                    cnt.at(i) %= 2;
                }
            }
        }
        if(cnt == p) ans++;
    }
    cout << ans << endl;
}
