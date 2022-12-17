#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
//#define SIZE
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
    ll res=1; while(n--) res *= x;
    return res;
}

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h), t(h);
    rep(i, h) cin >> s.at(i);
    rep(i, h) cin >> t.at(i);

    map<string, int> mp;
    rep(j, w){
        string row;
        rep(i, h){
            row += s.at(i).at(j);
        }
        mp[row]++;
    }

    rep(j, w){
        string row;
        rep(i, h){
            row += t.at(i).at(j);
        }
        mp[row]--;
    }
    for(auto iter: mp){
        if(iter.second != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
