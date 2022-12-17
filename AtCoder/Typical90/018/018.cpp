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
    double t; cin >> t;
    double l, x, y; cin >> l >> x >> y;
    int q; cin >> q;
    double pi = 3.1415926535;

    while(q--){
        int e; cin >> e;
        double len = l / 2;
        double ey = -len * cos(2*pi * e/t - 2*pi / 4);
        double ez = len + len * sin(2*pi * e/t - 2*pi / 4);
        double dx, dy, dz;
        dx = ez;
        dy = sqrt((ey - y) * (ey - y) + x * x);
        dz = sqrt(x * x + (y - ey) * (y - ey) + ez * ez);
        double theta = acos((dy * dy + dz * dz - dx * dx) / (2 * dy * dz));
        cout << setprecision(10) <<  theta / pi * 180 << endl;
    }
}
