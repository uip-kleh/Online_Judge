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

/*
参考サイト：http://www.thothchildren.com/chapter/5b267a436298160664e80763
*/
bool sign(ip p1, ip p2, ip p3){
    return (p1.first - p3.first) * (p2.second - p3.second) - (p2.first - p3.first) * (p1.second - p3.second) < 0;
}

bool is_in_triangle(ip in_point, vector<ip> points){
    vector<ip> triangle;
    for(auto point: points){
        if(point == in_point) continue;
        triangle.push_back(point);
    }
    bv b(3);
    rep(i, 3) b.at(i) = sign(in_point, triangle.at(i%3), triangle.at((i+1)%3));
    return (b.at(0) == b.at(1) and b.at(1) == b.at(2)); 
}

int main(){
    vector<ip> points;
    rep(i, 4){
        int x, y; cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    bool is_rectangle = true;
    rep(i, 4){
        if(is_in_triangle(points.at(i), points)) is_rectangle = false;
    }
    cout << (is_rectangle ? "Yes" : "No") << endl;
}   