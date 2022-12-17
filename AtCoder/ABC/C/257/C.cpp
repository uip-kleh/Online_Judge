#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, ans=0, cnt=0;
    string s;
    cin >> n >> s;
    vector<pair<int, char>> pvec;
    for(int i=0; i<n; i++){
        int w;
        cin >> w;
        //pvec.push_back(make_pair(w, s.at(i)));
        if(s.at(i) == '1') ans++;
    }
    sort(pvec.begin(), pvec.end());
    cnt = ans;
    for(int i=0; i<n; i++){
        if(pvec.at(i).second == '1') cnt--;
        else cnt++;
        if(i < n - 1){
            if(pvec.at(i).first != pvec.at(i+1).first) ans = max(ans, cnt);
        }
        else{
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}