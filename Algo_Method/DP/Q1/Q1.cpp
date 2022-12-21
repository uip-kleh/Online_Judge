#include<iostream>
#include<vector>
using namespace std;

int main(){
    // input
    int n, x, y; cin >> n >> x >> y;
    vector<int> dp(n+1);

    // init
    dp.at(0) = x;
    dp.at(1) = y;
    for(int i=2; i<n; i++){
        dp.at(i) = dp.at(i-1) + dp.at(i-2); 
        dp.at(i) %= 100;
    }
    cout << dp.at(n-1) << endl;
}