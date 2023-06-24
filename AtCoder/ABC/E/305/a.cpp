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
void print(iv &a){
    for(auto v: a) cout << v << ' ';
    cout << endl;
}

int main() {
    int N, M, K; cin >> N >> M >> K;
    ivv g(N);
    rep(i, M){
        int a, b; cin >> a >> b, --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    iv gaurd(N, -1);
    priority_queue<ip> pq;
    rep(i, K){
        int p, h; cin >> p >> h, --p;
        gaurd[p] = h;
        pq.push(make_pair(h, p));
    }

    while(!pq.empty()){
        ip iter = pq.top(); pq.pop();
        int now = iter.second;
        if(gaurd[now] > iter.first) continue;
        for(auto nv: g[now]){
            if(gaurd[nv] < gaurd[now] - 1){
                gaurd[nv] = gaurd[now] - 1;
                pq.push(make_pair(gaurd[nv], nv));
            }
        }
    }

    iv ans;
    rep(i, N){
        if(gaurd[i] >= 0) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(auto v: ans){
        cout << v + 1 << ' ';
    }
    cout << endl;
}
