#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int n, ans=0;
    cin >> n;
    map<int, int> m;
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        p = (i - p) % n;
        for(int j=0; j<3; j++){
            p += 1;
            p %= n;
            if(p < 0) p += n;
            if(m.find(p) == m.end()) m[p] = 0;
            m[p] += 1;
        }
    }
    for(auto iter: m){
        ans = max(ans, iter.second);
    }
    cout << ans << endl;
}