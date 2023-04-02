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
iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

int main(){
    int h, w, n; cin >> h >> w >> n;
    vector<string> s(h);
    rep(i, h) cin >> s.at(i);
    ip start;
    rep(i, h){
        rep(j, w){
            if(s.at(i).at(j) == 'S') start = make_pair(i, j);
        }
    }

    int level = 1;
    queue<ip> q; q.push(start);
    map<ip, ll> checked; checked[start] = 0;
    while(!q.empty()){
        ip present = q.front(); q.pop();
        rep(i, 4){

            if(s.at(present.first).at(present.second) - '0' == level){
                ll cnt = checked[present];
                if(level == n) cout << cnt << endl;
                // cout << level << ' ' << cnt << endl;
                level++;
                // init
                while(!q.empty()) q.pop();
                checked.clear();
                q.push(present);
                checked[present] = cnt;
            }

            ip next = make_pair(present.first + dx.at(i), present.second + dy.at(i));
            if(next.first < 0 or next.first >= h) continue;
            if(next.second < 0 or next.second >= w) continue;
            if(checked.find(next) != checked.end()) continue;
            if(s.at(next.first).at(next.second) == 'X') continue;
            checked[next] = checked[present] + 1;
            q.push(next);
        }
    }
}
