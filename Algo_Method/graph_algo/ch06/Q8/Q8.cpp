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

bv checked(SIZE, false), is_matched(SIZE, false);
ivv g(SIZE);
void dfs(int node, ivv &children, iv &parent){
    if(checked.at(node)) return;

    bool flag = true;
    checked.at(node) = true;
    for(auto new_node: g.at(node)){
        dfs(new_node, children, parent);
    }
    if(parent.at(node) == -1) return;
    if(!is_matched.at(node) && !is_matched.at(parent.at(node))){
        is_matched[node] = true;
        is_matched[parent.at(node)] = true;
    }
}

int main(){
    int n; cin >> n;
    rep(i, n-1){
        int a, b; cin >> a >> b;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    int r = 0;
    ivv children(n);
    iv parent(n, -1);
    bv seen(n); seen.at(r) = true;
    queue<int> q; q.push(r);
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto new_node: g.at(node)){
            if(seen.at(new_node)) continue;
            children.at(node).push_back(new_node);
            parent[new_node] = node;
            seen.at(node) = true;
            q.push(new_node);
        }
    }

    dfs(r, children, parent);

    ll ans = 0;
    rep(i, n){
        if(is_matched.at(i)) ans++;
    }
    cout << ans / 2 << endl;
}
