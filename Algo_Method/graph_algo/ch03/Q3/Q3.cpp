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
    int h, w; cin >> h >> w;
    int sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
    ip start, goal;
    start = make_pair(sx, sy); 
    goal = make_pair(gx, gy);
    vector<string> sv(h); rep(i, h) cin >> sv.at(i);
    
    pv v;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(abs(i) + abs(j) == 1){
                v.push_back(make_pair(i, j));
            }
        }
    }
    map<ip, int> checked;
    checked[start] = 0;
    queue<ip> q;
    q.push(start);
    while(!q.empty()){
        ip node = q.front(); q.pop();
        for(auto viter: v){
            auto new_node = make_pair(node.first + viter.first, node.second + viter.second);
            if(new_node.first < 0 or new_node.first >= h) continue;
            if(new_node.second < 0 or new_node.second >= w) continue;
            if(sv.at(new_node.first).at(new_node.second) == 'B') continue; 
            if(checked.find(new_node) != checked.end()) continue;
            q.push(new_node);
            checked[new_node] = checked[node] + 1;
        }
    }
    cout << checked[goal] << endl;
}
