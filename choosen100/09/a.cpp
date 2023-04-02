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

int main(){
    int n; cin >> n;
    vector<ip> find_coords, coords, vec;
    set<ip> st;
    rep(i, n){
        int a, b; cin >> a >> b;
        find_coords.push_back(make_pair(a, b));
    }
    rep(i, n-1){
        vec.push_back(make_pair(find_coords.at(i+1).first - find_coords.at(0).first, find_coords.at(i+1).second - find_coords.at(0).second));
    }
    // rep(i, n-1){
    //     cout << vec.at(i).first << ' ' << vec.at(i).second << endl;
    // }
    int m; cin >> m;
    rep(i, m){
        int a, b; cin >> a >> b;
        coords.push_back(make_pair(a, b));
        st.insert(make_pair(a, b));
    }
    rep(i, m){
        bool canmake = true;
        // cout << "start:" << coords.at(i).first << ' ' << coords.at(i).second << endl;
        rep(j, n-1){
            ip newpoint = make_pair(coords.at(i).first + vec.at(j).first, coords.at(i).second + vec.at(j).second);
            // cout << newpoint.first << ' ' << newpoint.second << endl;
            if(st.find(newpoint) == st.end()) canmake = false;
        }
        if(canmake){
            cout << coords.at(i).first - find_coords.at(0).first << ' ' << coords.at(i).second - find_coords.at(0).second << endl;
            return 0;
        }
    }
}
