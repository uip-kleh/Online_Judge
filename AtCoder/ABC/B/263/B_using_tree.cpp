#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, min_cnt = (1 << 21);
vector<vector<int>> G(51);

void search(int c, int cnt){
    if(c == n-1){
        min_cnt = min(min_cnt, cnt);
        return;
    }

    for(auto i: G.at(c)){
        search(i, cnt+1);
    }
}

int main(){
    cin >> n;
    for(int i=1; i<n; i++){
        int p; 
        cin >> p;
        G.at(p-1).push_back(i);
    }

    int c = 0, cnt = 0;
    search(c, cnt);

    cout << min_cnt << endl;
}