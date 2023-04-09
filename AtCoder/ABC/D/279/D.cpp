#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define SIZE 2e5
#define INF 1e9
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

struct edge {
    int from, to, length;
};

float fall_t(float a, float b, ll m){
    return a / sqrt(1 + m) + b * m;
}

int main(){
    ll a, b; cin >> a >> b;
    ll l = 0, r = 1e18;
    float ans = min(fall_t(a, b, l), fall_t(a, b, r));
    while(r - l > 2){
        ll d = r - l;
        ll lmid = l + d / 3, rmid = l + d * 2 / 3;
        float lmid_t = fall_t(a, b, lmid), rmid_t = fall_t(a, b, rmid);
        ans = min(ans, min(lmid_t, rmid_t));
        // cout << l << ' ' << r << endl;
        // cout << lmid << ' ' << lmid_t << ' ' << rmid << ' ' << rmid_t << endl;
        if(lmid_t > rmid_t) l = lmid;
        else r = rmid;
    }
    cout << setprecision(10) << ans << endl;
}
