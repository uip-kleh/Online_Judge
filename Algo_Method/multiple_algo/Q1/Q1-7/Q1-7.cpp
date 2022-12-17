#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> schedule;
    for(int i=0; i<n; i++){
        int s, t; cin >> s >> t;
        schedule.push_back(make_pair(t, s));
    }
    sort(schedule.begin(), schedule.end());
    int pre = 0, cnt = 1;
    for(auto iter: schedule){
        int t = iter.first, s = iter.second;
        if(pre == 0) pre = t;
        if(pre <= s){
            pre = t;
            cnt++;
        }
    }
    cout << cnt << endl;
}