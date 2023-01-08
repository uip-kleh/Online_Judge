#include<iostream>
#include<vector>
#define MAX 105
using namespace std;

vector<vector<int>> g(MAX);
vector<bool> checked(MAX, false);

void dfs(int node){
    // basecase
    if(checked.at(node)) return;

    // step
    checked.at(node) = true;
    for(int new_node: g.at(node)) dfs(new_node);
}

int main(){
    // input
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v, --u, --v;
        g.at(u).push_back(v);
        g.at(v).push_back(u);
    }

    // DFS
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(checked.at(i)) continue;
        dfs(i);
        cnt++;
    }

    // DISP
    cout << cnt << endl;
}