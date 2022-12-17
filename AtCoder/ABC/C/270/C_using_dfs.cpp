#include<iostream>
#include<vector>
#include<queue>
#define MAX 20e5 + 5
using namespace std;

bool fin = false;
vector<bool> checked(MAX, false);
vector<vector<int>> g(MAX);
deque<int> deq;

void dfs(int node, int goal){
    // basecase
    if(checked.at(node)) return;
    if(!fin) deq.push_back(node);
    if(node == goal) fin = true;

    // step 
    checked.at(node) = true;
    for(auto new_node: g.at(node)){
        dfs(new_node, goal);
    }
    if(!fin) deq.pop_back();
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g.at(u-1).push_back(v-1);
        g.at(v-1).push_back(u-1);
    }

    dfs(x-1, y-1);

    while(!deq.empty()){
		cout<<deq.front() + 1;
		deq.pop_front();
		if(deq.empty())cout<<endl;
		else cout<<" ";
	}
}