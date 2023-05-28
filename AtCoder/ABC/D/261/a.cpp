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

void print(iv &a){
    for(auto v: a) cout << v << ' ';
    cout << endl;
}


iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

struct edge {
    int from, to, length;
};

int main() {
    int N, M; cin >> N >> M;
    iv X(N); rep(i, N) cin >> X[i];
    map<int, int> B;
    rep(i, M){
        int C, Y; cin >> C >> Y, C;
        B[C] = Y;
    }


    ivv DP(N+1, iv(N+1, -INF));
    DP[0][0] = 0;

    nrep(i, N){
        nrep(j, N){
            DP[i][j] = DP[i-1][j-1] + X[i-1] + B[j];
        }
        DP[i][0] = 0;
        rep(j, i){
            DP[i][0] = max(DP[i][0], DP[i-1][j]);
        }
    }

    ll ans = -INF;
    for(auto v: DP.back()) ans = max(ans, v);
    cout << ans << endl;

    // DISP
    // rep(i, N+1){
    //     print(DP[i]);
    // }
}
