#include<iostream>
#include<vector>
#include<algorithm>
#define INF 10e9
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h.at(i);

    vector<ll> dp(n, INF);
    dp.at(0) = 0;
    dp.at(1) = abs(h.at(0) - h.at(1));
    for(int i=2; i<n; i++){
        for(int j=1; j<k+1; j++){
            if(i - j < 0) continue;
            dp.at(i) = min(dp.at(i), dp.at(i-j) + abs(h.at(i) - h.at(i-j)));
        }
    }

    cout << dp.at(n-1) << endl;
}