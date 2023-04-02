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
iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

int main(){
    int n, m; cin >> n >> m;
    iv c(m); rep(i, m) cin >> c.at(i);
    ivv dp(m+1, iv(n+1, 1e18));
    rep(i, m+1) dp.at(i).at(0) = 0;
    nrep(i, m){
        rep(j, n+1){
            if(j - c.at(i-1) >= 0){
                dp.at(i).at(j) = min(dp.at(i).at(j-c.at(i-1)) + 1, dp.at(i-1).at(j));
            }
            else{
                dp.at(i).at(j) = dp.at(i-1).at(j);
            }
        }
    }
    // nrep(i, m){
    //     rep(j, n+1){
    //         cout << dp.at(i).at(j) << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp.at(m).at(n) << endl;
}
