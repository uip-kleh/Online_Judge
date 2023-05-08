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
    int n; cin >> n;
    vector<string> s(n); rep(i, n) cin >> s[i];

    vector<ll> dpT(n+1), dpF(n+1);
    dpT[0] = 1; dpF[0] = 1;
    nrep(i, n){
        if(s[i-1] == "AND"){
            dpT[i] += dpT[i-1];
            dpF[i] += dpT[i-1] + 2*dpF[i-1];
        }
        if(s[i-1] == "OR"){
            dpT[i] += 2*dpT[i-1] + dpF[i-1];
            dpF[i] += dpF[i-1];
        }
    }
    // rep(i, n+1){
    //     cout << dpT[i] << ' ';
    // }
    // cout << endl;
    // rep(i, n+1){
    //     cout << dpF[i] << ' ';
    // }
    // cout << endl;
    cout << dpT[n] << endl;
}
