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
iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

struct edge {
    int from, to, length;
};

int main(){
    int H, W; cin >> H >> W;
    vector<string> C(H); rep(i, H) cin >> C.at(i);
    int n = min(H, W);
    iv ans(n);
    rep(a, H){
        rep(b, W){
            if(C[a][b] == '.') continue;
            // (a, b)を中心として考える
            int dist = -1;
            nrep(d, n){
                int a1 = a + d, a2 = a - d;
                int b1 = b + d, b2 = b - d;
                if(a1 >= H or a2 < 0) break;
                if(b1 >= W or b2 < 0) break;
                if(C[a1][b1] != '#' or C[a1][b2] != '#' or C[a2][b1] != '#' or C[a2][b2] != '#') break;
                dist = d;
            }
            if(dist != -1) ans[dist-1]++;
        }
    }
    rep(i, n) cout << ans.at(i) << ' ' ;
    cout << endl;
}
