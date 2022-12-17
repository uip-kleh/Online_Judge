#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int max_cnt = 0;
int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};
map<pair<int, int>, bool> checked;

void search(int cnt, pair<int, int> iter){
    // basecase
    if(checked.find(iter) == checked.end()) return;
    if(checked.at(iter)) return;

    // ster
    if(cnt == 1 && !checked.at(iter)) max_cnt++;
    checked.at(iter) = true;
    for(int i: dx){
        for(int j: dy){
            if(i + j != 0 && i + j < 3){
                pair<int, int> new_iter = make_pair(iter.first + i, iter.second + j);
                if(checked.find(new_iter) != checked.end()){
                    search(cnt+1, new_iter);
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> points;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
        checked[make_pair(x, y)] = false;
    }
    int cnt = 0;
    for(auto iter: points){
        search(1, iter);
    }
    cout << max_cnt << endl;
}