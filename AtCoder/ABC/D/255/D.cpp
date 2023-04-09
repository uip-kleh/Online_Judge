#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define SIZE 2e5
#define INF 2e18
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

int main(){
    int n, q; cin >> n >> q;
    iv a(n); rep(i, n) cin >> a.at(i);
    sort(all(a));
    iv sum(n);
    rep(i, n){
        if(i == 0) sum.at(i) = a.at(i);
        else sum.at(i) = sum.at(i-1) + a.at(i);
    }
    // rep(i, n) cout << sum.at(i) << ' ';
    // cout << endl;
    while(q--){
        ll x; cin >> x;
        auto iter = lower_bound(all(a), x);
        int index = distance(a.begin(), iter);
        // cout << "index:" << ' ' << index << endl;
        if(index == n or index == 0) cout << abs(sum.back() - x * n) << endl;
        else {
            // cout << abs(sum.at(index-1) - x * index) << ' ' << abs(sum.back() - x * (n - index)) << endl;
            cout << abs(sum.at(index-1) - x * index) + abs(sum.back() - sum.at(index - 1) - x * (n - index)) << endl;
        }
    }
}
