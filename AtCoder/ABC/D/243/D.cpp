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
typedef vector<ll> lv;
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

// N の約数をすべて求める関数

iv calc_divisors(long long N) {
    vector<long long> res;

    for (long long i = 1; i * i <= N; ++i) {
        if (N % i != 0) continue;
        res.push_back(i);
        if (N / i != i) res.push_back(N / i);
    }
    
    return res;
}

int main(){
    int n; cin >> n;
    iv a(n);
    unordered_map<ll, ll> mp;
    rep(i, n){
        cin >> a.at(i);
        mp[a.at(i)] += 1;
    }
    ll cnt = 0;
    for(auto iter: mp){
        ll ai = iter.first;
        iv res = calc_divisors(ai);
        for(auto aj: res){
            ll ak = ai / aj;
            if(mp.find(ak) != mp.end() && mp.find(aj) != mp.end()){
                cnt += mp.at(ai) * mp.at(aj) * mp.at(ak);
            }
        }
    }
    cout << cnt << endl;
}

