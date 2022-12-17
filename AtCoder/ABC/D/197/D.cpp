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
    static const double pi = 3.141592653589793;
    int n; cin >> n;
    pair<double, double> p0, p1, p2, pmid;
    int x, y; 
    cin >> x >> y;
    p0 = make_pair(x, y);
    cin >> x >> y;
    p2 = make_pair(x, y);
    pmid = make_pair((p0.first + p2.first)/2, (p0.second + p2.second)/2);
    double arg = 2 * pi / n;
    p0 = make_pair(p0.first - pmid.first, p0.second - pmid.second);
    p1.first = p0.first * cos(arg) - p0.second * sin(arg) + pmid.first;
    p1.second = p0.first * sin(arg) + p0.second * cos(arg) + pmid.second;
    cout << p1.first << ' ' << p1.second << endl;
}
