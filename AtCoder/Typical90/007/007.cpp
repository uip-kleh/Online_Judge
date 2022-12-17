#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a.at(i);
    sort(a.begin(), a.end());

    int q;
    cin >> q;
    ll s = 0;
    while(q--){
        int b;
        cin >> b;
        int index = distance(a.begin(), lower_bound(a.begin(), a.end(), b));
        if(index == 0) cout << abs(a.at(0) - b) << endl;
        else if(index == n) cout << abs(a.at(n-1) - b) << endl;
        else cout << min(abs(a.at(index) - b), abs(a.at(index-1) - b)) << endl;
    }
}