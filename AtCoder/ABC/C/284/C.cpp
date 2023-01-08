#include<iostream>
#include<vector>
using namespace std;

struct UnionFind{
    // init
    vector<int> par, rank, siz;
    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    int root(int x){
        if(par.at(x) == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool is_same(int x, int y){
        return root(x) == root(y);
    }

    void unite(int x, int y){
        if(is_same(x, y)) return;
        int rx = root(x), ry = root(y);
        if(siz.at(rx) < siz.at(ry)) swap(rx, ry);
        par[ry] = rx;
        if(rank.at(rx) == rank.at(ry)) rank.at(rx)++;
        siz.at(rx) += siz.at(ry);
    }
};

int main(){
    int n, m; cin >> n >> m;
    UnionFind uf(n);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v, --u, --v;
        uf.unite(u, v);
    }
    int cnt = 0;
    for(auto p: uf.par){
        if(p == -1) cnt++;
    }
    cout << cnt << endl;
}