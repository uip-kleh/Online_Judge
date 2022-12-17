#include<iostream>
#include<vector>
#include<queue>
#define SIZE 2000
using namespace std;

int cnt = 0;
queue<int> q;
vector<vector<int>> g(SIZE);

void bfs(int node, int s, vector<bool> &checked){
    // basecase
    if(checked.at(node)) return;

    // step
    cnt++;
    checked.at(node) = true;
    for(auto new_node: g.at(node)){
        bfs(new_node, s, checked);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g.at(a-1).push_back(b-1);
    }

    for(int s=0;s <n; s++){
        vector<bool> checked(n, false);
        bfs(s, s, checked);
    }
    cout << cnt << endl;   
}