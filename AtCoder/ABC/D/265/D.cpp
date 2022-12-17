#include<iostream>
#include<set>
using namespace std;
typedef long long ll;

// LOG N
bool has_key(ll key, set<ll> &s){
    if(s.find(key) == s.end()) return false;
    return true;
}

int main(){
    // INPUT
    int n;
    ll p, q, r;
    cin >> n >> p >> q >> r;

    // 累積和のセットを作成
    ll crr=0;
    set<ll> s;
    s.insert(crr);   // INITIALIZE
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        crr += a;
        s.insert(crr);
    }

    bool can_make = false;
    for(auto x: s){
        if(has_key(x+p, s) && has_key(x+p+q, s) && has_key(x+p+q+r, s)) can_make = true;
    }

    cout << (can_make ? "Yes" : "No") << endl;
}