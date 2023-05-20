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
    int N, M; cin >> N >> M;
    iv A(N); rep(i, N) cin >> A[i];

    unordered_map<int, ll> mp;
    unordered_set<int> checked;
    ll asum = 0;
    for(auto v: A) mp[v]++;
    for(auto v: A) asum += v;

    iv vec = {-1, 1};

    // 探索
    ll ans = 2e18;
    for(auto iter: mp){
        int start = iter.first;
        if(checked.find(start) != checked.end()) continue;
        checked.insert(start);
        queue<int> q; q.push(start);
        ll sum = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            sum += node * mp[node];
            for(auto d: vec){
                int new_node = (node + d);
                if(new_node < 0) new_node += M;
                if(checked.find(new_node) != checked.end()) continue;
                if(mp.find(new_node) == mp.end()) continue;
                checked.insert(new_node);
                q.push(new_node);
            }
            for(auto d: vec){
                int new_node = (node + d) % M;
                if(new_node < 0) new_node += M;
                if(checked.find(new_node) != checked.end()) continue;
                if(mp.find(new_node) == mp.end()) continue;
                checked.insert(new_node);
                q.push(new_node);
            }
        }
        ans = min(ans, asum - sum);
    }

    cout << ans << endl;
    // DISPLAY
    // for(auto v: A) cout << v << ' ';
    // cout << endl;
}
