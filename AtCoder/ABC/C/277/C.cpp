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

int main(){
    int n; cin >> n;
    unordered_map<ll, set<ll>> stair;
    rep(i, n){
        int a, b; cin >> a >> b;
        stair[a].insert(b);
        stair[b].insert(a);
    }

    ll max_stair = 1;
    queue<ll> q; q.push(1);
    unordered_set<ll> checked; checked.insert(1);

    while(!q.empty()){
        ll node = q.front(); q.pop();
        if(stair.find(node) == stair.end()){
            max_stair = max(max_stair, node);
            continue;
        }
        for(auto new_node: stair.at(node)){
            if(checked.find(new_node) != checked.end()) continue;
            q.push(new_node);
            checked.insert(new_node);
            max_stair = max(max_stair, new_node);
        }
    }
    cout << max_stair << endl;
}

