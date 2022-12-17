#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
#define SIZE 2e5 + 5
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
    int n, x, y; cin >> n >> x >> y, x--, y--;
    ivv graph(SIZE);
    rep(i, n-1){
        int u, v; cin >> u >> v, u--, v--;
        graph.at(u).push_back(v);
        graph.at(v).push_back(u);
    }
    queue<int> q;
    unordered_map<int, vector<int>> checked;
    q.push(x);
    checked[x].push_back(x);
    while(!q.empty()){
        int node = q.front(); q.pop();
        
        for(auto new_node: graph.at(node)){
            if(checked.find(new_node) != checked.end()) continue;
            q.push(new_node);
            checked[new_node] = checked.at(node); checked.at(new_node).push_back(new_node);
        }
    }
    vector<int> ans = checked.at(y);
    rep(i, ans.size()){
        cout << ans.at(i) + 1;
        cout << (i == ans.size() - 1 ? "\n" : " ");
    }
}
