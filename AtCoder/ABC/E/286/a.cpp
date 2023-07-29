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
typedef vector<int> iv;
typedef vector<ll> lv;
typedef vector<bool> bv;
typedef pair<ll, ll> ip;
typedef vector<ip> pv;
typedef vector<iv> ivv;
typedef set<int> ist;
typedef set<ll> lst;
typedef map<int, int> imp;
typedef map<ll, ll> lmp;
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

void print(iv &a) {
    for (auto v : a) cout << v << ' ';
    cout << endl;
}

int calc(int N, ivv &G){
    int ans = 0, limit = 1e6;
    bv checked(N);
    auto dfs = [&](auto self, int node) -> void {
        if(ans == limit) return;
        ans++;
        checked[node] = true;
        for(auto newnode: G[node]){
            if(checked[newnode]) continue;
            self(self, newnode);
        }
        checked[node] = false;
    };
    dfs(dfs, 0);
    return ans;
}

int main() {
    int N, M; cin >> N >> M;
    ivv G(N);
    rep(i, M){
        int u, v; cin >> u >> v, --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout << calc(N, G) << endl;
}

