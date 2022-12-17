#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int r, c, sy, sx, gy, gx;
vector<string> svec;

int main(){
    // INPUT
    cin >> r >> c >> sy >> sx >> gy >> gx;
    for(int i=0; i<r; i++){ 
        string s;
        cin >> s;
        svec.push_back(s);
    }

    // INITIALIZE
    queue<pair<int, int>> q;
    vector<vector<int>> checked(r, vector<int>(c, -1));
    pair<int, int> goal = make_pair(gy-1, gx-1);
    q.push(make_pair(sy-1, sx-1));
    checked.at(sy-1).at(sx-1) = 0;
    

    // bfs
    while(!q.empty()){
        pair<int, int> iter = q.front();
        q.pop();
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(i != 0 && j != 0) continue;
                if(iter.first + i < 0 || iter.first + i >= r) continue;
                if(iter.second + j < 0 || iter.second + j >= c) continue;
                if(checked.at(iter.first+i).at(iter.second+j) == -1 && svec.at(iter.first+i).at(iter.second+j) == '.'){
                    q.push(make_pair(iter.first + i, iter.second + j));
                    checked.at(iter.first+i).at(iter.second + j) = checked.at(iter.first).at(iter.second) + 1;
                }
            }
        }
    }
    cout << checked.at(goal.first).at(goal.second) << endl;
}