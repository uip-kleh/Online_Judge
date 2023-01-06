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
    int get_siz(int x){
        return siz.at(root(x));
    }
};

#define MAX 2e5

bool is_binary=true;
iv color(MAX, -1);
ivv g(MAX);

void dfs(int node, int c){
    // basecase 
    if(color.at(node) != -1){
        if(color.at(node) != c) is_binary = false;
        return;
    }

    // step
    color.at(node) = c;
    for(auto new_node: g.at(node)){
        dfs(new_node, (c+1) % 2);
    }
}

int main(){
    int n, m; cin >> n >> m;
    UnionFind uf(n);
    rep(i, m){
        int u, v; cin >> u >> v, --u, --v;
        g.at(u).push_back(v); 
        g.at(v).push_back(u);
        uf.unite(u, v);
    }   

    rep(i, n){
        if(color.at(i) != -1) continue;
        dfs(i, 0);
    }

    if(!is_binary){
        cout << 0 << endl;
        return 0;
    }    

    // 連結したグラフにおける色の個数
    iv even(n, 0), odd(n, 0);
    rep(i, n){
        if(color.at(i) == 0) even.at(uf.root(i))++;
        else odd.at(uf.root(i))++;
    }

    // cnt 
    ll cnt = 0;
    rep(i, n){
        // 同じ連結の個数
        if(color.at(i) == 0) cnt += odd.at(uf.root(i)) - g.at(i).size();
        else cnt += even.at(uf.root(i)) - g.at(i).size();

        // 異なる連結の個数
        cnt += n - uf.get_siz(i);
    }
    cout << cnt / 2 << endl;

}

