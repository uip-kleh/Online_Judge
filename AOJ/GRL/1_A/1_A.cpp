#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int v, e, r;
    cin >> v >> e >> r;
    vector< vector<int> > g(v);
    map<pair<int, int>, int> weight;
    for(int i=0; i<e; i++){
        int s, t, d;
        cin >> s >> t >> d;
        g.at(s).push_back(t);
        g.at(t).push_back(s);
        weight[make_pair(s, t)] = d;
    }
    
    // BFS
    map<int, int> checked;
    queue<int> q;
    checked[r] = 0;
    q.push(r);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        //for(auto new_node: g.at(node)){
        for(int i=0; i<g.at(node).size(); i++){
            int new_node = g.at(node).at(i);
            if(weight.find(make_pair(node, new_node)) == weight.end()) continue;
            if(checked.find(new_node) == checked.end()){
                // cannot find
                checked[new_node] = checked.at(node) + weight.at(make_pair(node, new_node));
                q.push(new_node);
            }
            else{
                // can find
                if(checked.at(new_node) > checked.at(node) + weight.at(make_pair(node, new_node))){
                    checked.at(new_node) = checked.at(node) + weight.at(make_pair(node, new_node));
                    q.push(new_node);
                }
            }
        }   
    }

    // DISP
    /*
    // disp graph
    for(int i=0; i<v; i++){
        cout << i << ':';
        for(auto node: g.at(i)){
            cout << node << ' ';
        }
        cout << endl;
    }
    */

    for(int i=0; i<v; i++){
        if(checked.find(i) == checked.end()) cout << "INF" << endl;
        else cout << checked.at(i) << endl;
    }
}