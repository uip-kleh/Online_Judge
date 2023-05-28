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
    ivv a(M, iv(N));
    rep(i, M){
        rep(j, N){
            cin >> a[i][j], --a[i][j];
        }
    }

    set<ip> st;
    rep(i, N){
        for(int j=i+1; j<N; j++){
            st.insert(make_pair(i, j));
        }
    }

    rep(i, M){
        rep(j, N-1){
            // cout << i << ' ' << j << endl;
            int b = a[i][j];
            int c = a[i][j+1];
            // cout << b << ',' << c << endl;
            if(b > c) swap(b, c);
            ip p = make_pair(b, c);
            if(st.find(p) != st.end()) st.erase(p);
        }
    }
    // for(auto iter: st){
    //     cout << iter.first << ' ' << iter.second << endl;
    // }
    cout << st.size() << endl;
}

