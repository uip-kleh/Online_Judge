#include<bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define nrep(i, n) for(ll i = 1; i < ll(n + 1); i++)
#define rrep(i, n) for(ll i = ll(n) - 1; i >= 0; i--)
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
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll digsum(ll n) {
    ll res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

ll pow(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n % 2) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

map<ll, ll> numeric_component(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; i++) {
        if (N % i != 0) continue;
        while (N % i == 0) {
            res[i]++;
            N /= i;
        }
    }
    if (N != 1) res[N]++;
    return res;
}

iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

struct edge {
    int from, to, length;
};

int main() {
    int N; cin >> N;
    iv a(N); rep(i, N) cin >> a[i];
    iv b(N); rep(i, N) cin >> b[i];
    iv x(N);
    sort(all(a));
    rep(i, N){
        x[i] = a[0] ^ b[i];
    }
    set<ll> st;
    rep(i, N){
        st.insert(b[i]);
    }

    set<ll> ans;
    for(ll xv: x){
        multiset<ll> mst;
        for(ll av: a){
            mst.insert(av ^ xv);
        }

        bool can = true;
        for(auto bv: b){
            auto iter = mst.find(bv);
            if(iter == mst.end()) {
                can = false;
                break;
            }
            mst.erase(iter);
        }
        if(can) ans.insert(xv);
    }
    cout << ans.size() << endl;
    for(auto v: ans) cout << v << endl;
}
