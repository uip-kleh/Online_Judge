#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n, m;
    long long t;
    cin >> n >> m >> t;
    vector<int> a;
    for(int i=1; i<n; i++){
        int val; 
        cin >> val;
        a.push_back(val);
    }
    map<int, int> mp;
    while(m--){
        int x, y;
        cin >> x >> y;
        mp[x-2] = y;
    }
    int i=0;
    bool goal=true;
    for(auto val: a){
        t -= val;
        if(t <= 0) goal = false;
        if(mp.find(i) != mp.end()) t += mp.at(i);
        i++;
    }
    cout << (goal ? "Yes" : "No") << endl;
}