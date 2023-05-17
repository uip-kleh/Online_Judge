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
map<ll, ll> split(ll N){
    map<ll, ll> res;
    for(ll i=2; i*i<=N; i++){
        if(N % i != 0) continue;
        while(N % i == 0){
            res[i]++;
            N /= i;
        }
    }
    if(N != 1) res[N]++;
    return res;
}

iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

struct edge {
    int from, to, length;
};

int main(){
    ll n, k; cin >> n >> k;
    iv a(n); rep(i, n) cin >> a[i];
    iv asum(n);
    rep(i, n){
        if(i == 0) asum[0] = a[0];
        else asum[i] = asum[i-1] + a[i];
    }

    ll ans = distance(lower_bound(all(asum), k), asum.end());
    rep(i, n){
        ans += distance(lower_bound(all(asum), k+asum[i]), asum.end());
    }
    cout << ans << endl;
}
