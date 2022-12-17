#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int sl=s.length(), tl=t.length();

    vector<vector<int>> dp(sl+1, vector<int>(tl+1));
    for(int i=0; i<sl+1; i++) dp.at(i).at(0) = 0;
    for(int i=0; i<tl+1; i++) dp.at(0).at(i) = 0;
    for(int i=1; i<sl+1; i++){
        for(int j=1; j<tl+1; j++){
            if(s.at(i-1) == t.at(j-1)) dp.at(i).at(j) = dp.at(i-1).at(j-1) + 1;
            else dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i).at(j-1));
        }
    }

    /*
    for(vector<int> v: dp){
        for(auto val: v) cout << val << ' ';
        cout << endl;
    }
    */

    int i=sl, j = tl;
    string ans;
    while(dp.at(i).at(j) != 0){
        //cout << i << ' ' << j << endl;
        if(s.at(i-1) == t.at(j-1)){
            ans += s.at(i-1);
            i--; j--;
        }
        else if(dp.at(i).at(j) == dp.at(i).at(j-1)){
            j--;
        }
        else{
            i--;
        }
    }
    for(int i=ans.length()-1; i>=0; i--){
        cout << ans.at(i);
    }
    cout << endl;
}