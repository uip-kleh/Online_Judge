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
    int N; cin >> N;
    map<ip, int> mp;
    rep(i, N){
        int t, x, a; cin >> t >> x >> a;
        mp[make_pair(t, x)] = a;
    }

    ivv dp(10e5+5, iv(5, -1));
    dp[0][0] = 0;
    nrep(t, 1e5){
        rep(i, 5){
            if(i == 0){
                // if(dp[t-1][0] == -1 and dp[t-1][1] == -1) continue;
                dp[t][i] = max(dp[t-1][0], dp[t-1][1]);
            }
            else if(i == 4){
                // if(dp[t-1][3] == -1 and dp[t-1][4] == -1) continue;
                dp[t][i] = max(dp[t-1][3], dp[t-1][4]);
            }
            else{
                // if(dp[t-1][i-1] == -1 and dp[t-1][i] == -1 and dp[t-1][i+1] == -1);
                dp[t][i] = max(dp[t-1][i-1], max(dp[t-1][i], dp[t-1][i+1]));
            }
            if(dp[t][i] != -1) dp[t][i] += mp[make_pair(t, i)];
        }
    }
    ll ans = 0;
    for(auto v: dp[1e5]){
        ans = max(ans, v);
    }
    cout << ans << endl;
}
