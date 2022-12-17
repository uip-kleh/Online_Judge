#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, w;
    cin >> n >> w;
    vector<int> weight(n), value(n);
    for(int i=0; i<n; i++){
        cin >> weight.at(i) >> value.at(i);
    }

    vector<vector<ll>> dp(n+1, vector<ll>(w+1));
    for(int i=0; i<n+1; i++) dp.at(i).at(0) = 0;
    for(int i=0; i<w+1; i++) dp.at(0).at(i) = 0;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(j - weight.at(i-1) >= 0){
                dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i-1).at(j - weight.at(i-1)) + value.at(i-1));
            }
            else{
                dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i).at(j-1));
            }
        }
    }
    cout << dp.at(n).at(w) << endl;
    /*
    for(vector<ll> v: dp){
        for(auto val: v){
            cout << val << '\t';
        }
        cout << endl;
    }
    */
}