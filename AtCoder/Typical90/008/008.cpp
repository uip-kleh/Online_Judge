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

int main(){
    int n;
    ll mod = 1e9 + 7;
    string s, ans = "atcoder";
    cin >> n >> s;

    ivv dp(7, iv(n+1, 0));
    rep(i, 7){
        for(int j=1; j<n+1; j++){
            if(ans.at(i) == s.at(j-1) and i != 0) dp.at(i).at(j) = (dp.at(i).at(j-1) + dp.at(i-1).at(j-1)) % mod; 
            else if(ans.at(i) == s.at(j-1) and i == 0) dp.at(i).at(j) = dp.at(i).at(j-1) + 1;
            else dp.at(i).at(j) = dp.at(i).at(j-1);
        }
    }


    cout << dp.at(6).at(n) << endl;
    rep(i, 7){
        rep(j, n+1){
            cout << dp.at(i).at(j) << ' '; 
        }
        cout << endl;
    }
}
