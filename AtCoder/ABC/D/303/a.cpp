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
    int x, y, z; cin >> x >> y >> z;
    string s; cin >> s;
    int n = s.length();
    iv dpon(n+1, 0);
    iv dpoff(n+1, 0);

    dpon[0] = z;
    nrep(i, n){
        if(s[i-1] == 'a'){
            dpoff[i] = min(dpoff[i-1] + x, dpon[i-1] + z + x);
            dpon[i] = min(dpon[i-1] + y, dpoff[i-1] + z + y);
        }
        if(s[i-1] == 'A'){
            dpoff[i] = min(dpoff[i-1] + y, dpon[i-1] + z + y);
            dpon[i] = min(dpon[i-1] + x, dpoff[i-1] + z + x);
        }
    }

    // for(auto v: dpoff) cout << v << ' ';
    // cout << endl;
    // for(auto v: dpon) cout << v << ' ';
    // cout << endl;
    cout << min(dpoff.back(), dpon.back()) << endl;
}

