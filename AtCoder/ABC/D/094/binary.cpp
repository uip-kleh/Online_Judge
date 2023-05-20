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
    int n; cin >> n;
    iv a(n); rep(i, n) cin >> a[i];

    sort(all(a));
    int maxv = *a.rbegin();
    int mid = min(n, int(lower_bound(all(a), maxv/2) - a.begin()));
    int left = max(0, mid-1), right = min(n, mid+1);
    int ans = a[mid];
    if(maxv - ans <= min(a[left], maxv - a[left])) ans = min(a[left], maxv - a[left]);
    cout << maxv << ' ' << ans << endl;
}
