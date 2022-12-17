#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    vector<pair<int, int>> query;
    cin >> n;
    while(n--){
        int l, r;
        cin >> l >> r;
        query.push_back(make_pair(l, false));
        query.push_back(make_pair(r, true));
    }
    sort(query.begin(), query.end());
    int cnt=0;
    for(auto iter: query){
        if(!iter.second){
            if(cnt == 0) cout << iter.first << ' ';
            cnt++;
        }
        else{
            cnt--;
            if(cnt == 0) cout << iter.first << endl;
        }
    }
}