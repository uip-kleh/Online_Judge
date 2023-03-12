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
    ll res=1; while(n--) res *= x;
    return res;
}

struct UnionFind{
    iv par, rank, siz, min_node;
    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}
    
    int root(int x){
        if(par.at(x) == -1) return x;
        else return par.at(x) = root(par.at(x));
    }
    bool is_same(int x, int y){
        return root(x) == root(y);
    }
    bool unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(is_same(x, y)) return false;
        if(siz.at(rx) < siz.at(ry)) swap(rx, ry);
        par.at(ry) = rx;
        if(rank.at(rx) == rank.at(ry)) rank.at(rx) += 1;
        siz.at(rx) += siz.at(ry);
        return true;
    }
};

const int mod = 998244353;
iv dp1(SIZE, 1), dp2(SIZE, 1);
bv checked(SIZE, false);
ivv g(SIZE), children(SIZE);
void dfs(int node){
    if(checked.at(node)) return;

    checked.at(node) = true;
    for(auto new_node: children.at(node)){
        dfs(new_node);
        dp1.at(node) *= dp2.at(new_node);
        dp1.at(node) %= mod;
        dp2.at(node) *= (dp1.at(new_node) + dp2.at(new_node));
        dp2.at(node) %= mod;
    }
}

int main(){
    int n; cin >> n;
    rep(i, n-1){
        int a, b; cin >> a >> b;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    queue<int> q; q.push(0);
    map<int, int> checked; checked[0] = 0;
    while(!q.empty()){
        int node=q.front(); q.pop();
        for(int new_node: g.at(node)){
            if(checked.find(new_node) != checked.end()) continue;
            checked[new_node] = checked[node] + 1;
            children.at(node).push_back(new_node);
            q.push(new_node);
        }
    }

    dfs(0);

    cout << (dp1.at(0) + dp2.at(0)) % mod << endl;
}
