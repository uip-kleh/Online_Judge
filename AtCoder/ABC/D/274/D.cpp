#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
//#define SIZE
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

struct pair_hash{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const{
        std:size_t h1 = std::hash<T1>()(pair.fist);
        std::size_t h2 = std::hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};

int main(){
    int n, x, y; cin >> n >> x >> y;
    iv a(n); rep(i, n) cin >> a.at(i);
    set<int> xco, yco;
    xco.insert(a.at(0));
    yco.insert(0);
    for(int i=1; i<n; i++){
        set<int> new_xco, new_yco;
        if(i % 2 == 0){
            for(auto val: xco){
                new_xco.insert(val + a.at(i));
                new_xco.insert(val - a.at(i));
            } 
            xco = new_xco;
        }
        else{
            for(auto val: yco){
                new_yco.insert(val + a.at(i));
                new_yco.insert(val - a.at(i));
            }
            yco = new_yco;
        }
    }

    cout << (xco.find(x) != xco.end() and yco.find(y) != yco.end() ? "Yes" : "No") << endl;
}
