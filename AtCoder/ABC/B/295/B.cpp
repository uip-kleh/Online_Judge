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

iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};
vector<string> b(20);

int main(){
    int r, c; cin >> r >> c;
    vector<string> b(r); rep(i, r) cin >> b.at(i);
    rep(i, r){
        rep(j, c){
            if(b.at(i).at(j) == '#' or b.at(i).at(j) == '.') continue;
            int num = b.at(i).at(j) - '0';
            iv dx, dy;
            for(int k=-num; k<num+1; ++k){
                for(int l=-num; l<num+1; ++l){
                    if(abs(k) + abs(l) > num) continue;
                    dx.push_back(k);
                    dy.push_back(l); 
                }
            }
            rep(k, dx.size()){
                // cout << dx.at(k) << ' ' << dy.at(k) << endl;
                int newi = i + dx.at(k);
                int newj = j + dy.at(k);
                // cout << newi << ',' << newj << endl;
                if(newi < 0 or newi >= r) continue;
                if(newj < 0 or newj >= c) continue;
                if(b.at(newi).at(newj) >= '1' and b.at(newi).at(newj) <= '9') continue;
                b.at(newi).at(newj) = '.';
            }   
        }
    }
    rep(i, r){
        rep(j, c) {
            if(b.at(i).at(j) == '#' or b.at(i).at(j) == '.') continue;
            b.at(i).at(j) = '.';
        }
    }
    rep(i, r){
        cout << b.at(i) << endl;
    }
}
