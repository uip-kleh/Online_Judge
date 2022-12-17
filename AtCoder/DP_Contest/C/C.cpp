#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> dpa(n), dpb(n), dpc(n);
    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(i == 0){
            dpa.at(0) = a; dpb.at(0) = b; dpc.at(0) = c;
        }
        else{
            dpa.at(i) = max(dpb.at(i-1) + a, dpc.at(i-1) + a);
            dpb.at(i) = max(dpa.at(i-1) + b, dpc.at(i-1) + b);
            dpc.at(i) = max(dpa.at(i-1) + c, dpb.at(i-1) + c);
        }
    }

    cout << max(dpa.at(n-1), max(dpb.at(n-1), dpc.at(n-1))) << endl;
    /*
    for(auto val: dpa) cout << val << ' ';
    cout << endl;
    for(auto val: dpb) cout << val << ' ';
    cout << endl;
    for(auto val: dpc) cout << val << ' ';
    cout << endl;
    */
}