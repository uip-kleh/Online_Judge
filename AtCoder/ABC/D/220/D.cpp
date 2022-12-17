#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
//#define SIZE
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
    ll res=1; while(n--) res *= x;
    return res;
}

int main(){
    int n; cin >> n;
    ll mod = 998244353;
    iv a(n); rep(i, n) cin >> a.at(i);
    ivv dp(n+1, iv(10, 0));
    dp[0][a[0]] = 1;
    for(int i=1; i<n; i++){
        rep(j, 10){
            dp[i][(a[i] + j) % 10] += dp[i-1][j];
            dp[i][(a[i] + j) % 10] %= mod;
            dp[i][(a[i] * j) % 10] += dp[i-1][j];
            dp[i][(a[i] * j) % 10] %= mod;
        }
    }
    rep(i, 10){
        cout << dp[n-1][i] << endl;
    }
}
