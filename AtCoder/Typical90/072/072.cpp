#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
#define SIZE 2e5
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

bool is_prime(ll x){
    if(x < 2) return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(ll i=0; i<x; i++) if(x%i == 0) return 0;
    return 0;
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

void disp_dp(ivv &dp){
    for(iv p: dp){
        for(auto v: p) cout << v << ' ';
        cout << endl;
    }
}

int h, w; 
vector<vector<char>> c(20, vector<char>(20));
iv dx = { 0, 1, 0, -1 };
iv dy = { 1, 0, -1, 0 };
vector<bv> used(20, bv(20, false));

ll dfs(int sx, int sy, int px, int py){
    if(sx == px && sy == py && used.at(px).at(py)) return 0;
    used.at(px).at(py) = true;
    ll mx = -10000;
    rep(i, 4){
        int nx = px + dx.at(i);
        int ny = py + dy.at(i);
        if(nx < 1 || ny < 1 || nx > h || ny > w) continue;
        if(c.at(nx).at(ny) != '.') continue;
        if((sx != nx || sy != ny) && used.at(nx).at(ny)) continue;
        ll v = dfs(sx, sy, nx, ny);
        mx = max(mx, v+1); 
    } 
    used.at(px).at(py) = false;
    return mx;
}

int main(){
    cin >> h >> w;  
    nrep(i, h){
        nrep(j, w){
            cin >> c.at(i).at(j);
        }
    };

    ll ans = -1;
    nrep(i, h){
        nrep(j, w){
            ans = max(ans, dfs(i, j, i, j));
        }
    }
    if(ans <= 2) ans = -1;
    cout << ans << endl;
}
