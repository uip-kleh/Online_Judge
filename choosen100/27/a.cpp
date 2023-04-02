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

iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

int h, w;
const int isize = 80;
ll ans = 0;
ivv c(isize, iv(isize));
vector<bv> globalchecked(isize, bv(isize, false)), checked(isize, bv(isize, false));
void dfs(int i, int j, int cnt){
    if(i < 0 or i >= h) return;
    if(j < 0 or j >= w) return;
    if(c.at(i).at(j) == 0) return;
    if(checked.at(i).at(j)) return;

    ans = max(ans, ll(cnt));
    globalchecked.at(i).at(j) = true;
    checked.at(i).at(j) = true;
    rep(k, 4){
        int newi = i + dx.at(k);
        int newj = j + dy.at(k);
        dfs(newi, newj, cnt+1);
    }
    checked.at(i).at(j) = false;
}

int main(){
    cin >> w >> h;
    rep(i, h){
        rep(j, w){
            cin >> c.at(i).at(j);
        }
    }

    rep(i, h){
        rep(j, w){
            // if(globalchecked.at(i).at(j) or c.at(i).at(j) == 0) continue;
            dfs(i, j, 0);
        }
    }
    cout << ans + 1 << endl;
}
