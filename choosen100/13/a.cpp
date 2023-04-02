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
    int r, c; cin >> r >> c;
    ivv a(r, iv(c));
    rep(i, r){
        rep(j, c) cin >> a.at(i).at(j);
    }
    ll ans = 0;
    for(int bits=0; bits<(1<<r); bits++){
        ll cnt = 0;
        rep(i, c){
            ll cnt0 = 0, cnt1 = 0;
            rep(j, r){
                if(bits & (1<<j)){
                    if(a.at(j).at(i) == 0) cnt1++;
                    if(a.at(j).at(i) == 1) cnt0++;
                }
                else{
                    if(a.at(j).at(i) == 1) cnt1++;
                    if(a.at(j).at(i) == 0) cnt0++;
                }
            }
            cnt += max(cnt0, cnt1);
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
