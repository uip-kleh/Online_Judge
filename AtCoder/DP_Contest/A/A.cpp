#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h.at(i);
    }

    vector<int> dp(n);
    dp.at(0) = 0;
    dp.at(1) = abs(h.at(0) - abs(h.at(1)));
    for(int i=2; i<n; i++){
        dp.at(i) = min(dp.at(i-1) + abs(h.at(i) - h.at(i-1)), dp.at(i-2) + abs(h.at(i) - h.at(i-2)));
    }

    cout << dp.at(n-1) << endl;
}