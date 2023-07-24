#include<bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define nrep(i, n) for(ll i = 1; i < ll(n + 1); i++)
#define rrep(i, n) for(ll i = ll(n) - 1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define SIZE 2e5
#define INF 2e18
constexpr long long MOD = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef vector<int> iv;
typedef vector<ll> lv;
typedef vector<bool> bv;
typedef pair<ll, ll> ip;
typedef vector<ip> pv;
typedef vector<iv> ivv;
typedef set<int> ist;
typedef set<ll> lst;
typedef map<int, int> imp;
typedef map<ll, ll> lmp;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll digsum(ll n) {
    ll res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

ll pow(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n % 2) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

map<ll, ll> numeric_component(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; i++) {
        if (N % i != 0) continue;
        while (N % i == 0) {
            res[i]++;
            N /= i;
        }
    }
    if (N != 1) res[N]++;
    return res;
}

iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

struct edge {
    int from, to, length;
};

void print(iv &a) {
    for (auto v : a) cout << v + 1 << ' ';
    cout << endl;
}

struct UnionFind {
    iv par, rank, siz, min_node;
    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    int root(int x) {
        if (par.at(x) == -1) return x;
        else return par.at(x) = root(par.at(x));
    }

    bool is_same(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        int rx = root(x), ry = root(y);
        if (is_same(x, y)) return false;
        if (siz.at(rx) < siz.at(ry)) swap(rx, ry);
        par.at(ry) = rx;
        if (rank.at(rx) == rank.at(ry)) rank.at(rx) += 1;
        siz.at(rx) += siz.at(ry);
        return true;
    }
};

bool isfin = true;
iv path;
map<int, int> checked;
void dfs(int node, int start, int goal, ivv &G){
    // cout << node << "=>" << endl;
    if(checked[node] == 1 and node == start){
        return;
    }
    // cout << 0 << endl;
    if(checked[node] == 1) return;
    // cout << 1 << endl;
    checked[node]++;
    for(auto newnode: G[node]){
        path.push_back(newnode);
        dfs(newnode, start, goal, G);
        if(isfin) return;
        path.pop_back();
    }

}

int main() {
    int N; cin >> N;
    UnionFind uf(N);
    ivv G(N);
    iv A(N);
    ip nodepair;
    rep(i, N){
        int a; cin >> a, --a;
        if(uf.is_same(i, a)) nodepair = {i, a};
        uf.unite(i, a);
        G[i].push_back(a);
    }

    // cout << nodepair.first << ' ' << nodepair.second << endl;
    path.push_back(nodepair.first);
    dfs(nodepair.first, nodepair.first, nodepair.second, G);

    // cout << "========" << endl;
    path.pop_back();
    cout << path.size() << endl;
    print(path);

    // rep(i, N){
    //     cout << i << ':';
    //     print(G[i]);
    // }
}
