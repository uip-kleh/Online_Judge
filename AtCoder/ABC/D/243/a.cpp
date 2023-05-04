#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define SIZE 2e5
#define INF 2e18
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
iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

struct edge {
    int from, to, length;
};

int main(){
    ll n, x; cin >> n >> x;
    string s; cin >> s;
    deque<char> dq;
    for(auto c: s){
        if(dq.empty()){
            dq.push_back(c);
            continue;
        }
        // if(c == 'U'){
        //     if(dq.back() != 'U') dq.pop_back();
        // }
        if(c == 'U' and dq.back() != 'U') dq.pop_back();
        else dq.push_back(c);
    }

    // deque<char> buf = dq;
    // while(!buf.empty()){
    //     cout << buf.front() << ' ' ;
    //     buf.pop_front();
    // }
    // cout << endl;

    while(!dq.empty()){
        char front = dq.front(); dq.pop_front();
        if(front == 'U') x /= 2;
        if(front == 'L') x *= 2;
        if(front == 'R') x = 2 * x + 1;
        // cout << x << endl;
    }
    cout << x << endl;
}
