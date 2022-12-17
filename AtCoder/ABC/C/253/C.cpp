#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int max_queue(map<int, int> &mp, priority_queue<int> &pq){
    int x;
    while(!pq.empty()){
        x = abs(pq.top());
        if(mp.at(x) != 0) break;
        pq.pop();
    }
    return x;
}

int main(){
    int q;
    cin >> q;
    map<int, int> mp;
    priority_queue<int> max_pq, min_pq;
    while(q--){
        int n;
        cin >> n;
        if(n == 1){
            int x;
            cin >> x;
            if(mp.find(x) == mp.end()) mp[x] = 0;
            mp.at(x)++;
            max_pq.push(x);
            min_pq.push(-x);
        }
        if(n == 2){
            int x, c;
            cin >> x >> c;
            if(mp.find(x) != mp.end()) mp.at(x) -= min(c, mp.at(x));
        }
        if(n == 3){
            cout << max_queue(mp, max_pq) -  max_queue(mp, min_pq) << endl;
        }
    }
}