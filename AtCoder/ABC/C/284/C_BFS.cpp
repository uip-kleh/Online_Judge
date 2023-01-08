#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

int main(){
    // input
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v, --u, --v;
        g.at(u).push_back(v);
        g.at(v).push_back(u);
    }

    // DFS
    int cnt = 0;
    unordered_set<int> checked;
    for(int i=0; i<n; i++){ // すべての頂点を始点とする
        if(checked.find(i) != checked.end()) continue;  // 探索済み
        cnt++;
        queue<int> q; q.push(i);
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int new_node: g.at(node)){
                if(checked.find(new_node) != checked.end()) continue;
                q.push(new_node);
                checked.insert(new_node);
            }
        }
    }
    
    // DISP
    cout << cnt << endl;
}