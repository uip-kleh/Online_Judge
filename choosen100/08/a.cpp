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
    iv a(n), b(n);
    rep(i, n){
        cin >> a.at(i) >> b.at(i);
    }

    ll sum = 0;
    sort(all(a));
    sort(all(b));
    // nth_element(a.begin(), a.begin() + n/2, a.end());
    // nth_element(b.begin(), b.begin() + n/2, b.end());
    ll mediuna = a.at(n/2), mediunb = b.at(n/2);
    rep(i, n){
        sum += abs(a.at(i) - b.at(i));
        sum += abs(a.at(i) - mediuna);
        sum += abs(b.at(i) - mediunb);
    }
    cout << sum << endl;
}
