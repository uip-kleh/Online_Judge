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

ll calcS(ll dx, ll dy){
    return dx * dx + dy * dy;
}

int main(){
    int n; cin >> n;
    vector<pair<ll, ll>> coords;
    set<pair<ll, ll>> st;
    rep(i, n){
        ll a, b; cin >> a >> b;
        coords.push_back(make_pair(a, b));
        st.insert(make_pair(a, b));
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ll dx, dy;
            dx = abs(coords.at(i).first - coords.at(j).first);
            dy = abs(coords.at(i).second - coords.at(j).second);
            ip p1, p2;
            p1 = make_pair(coords.at(i).first + dy, coords.at(i).second + dx);
            p2 = make_pair(coords.at(j).first + dy, coords.at(j).second + dx);
            if(st.find(p1) != st.end() and st.find(p2) != st.end()) ans = max(ans, calcS(dx, dy));
        }
    }
    cout << int(ans) << endl;
}
