#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

ll find_element(ll n){
    if(n % 2 == 0) return 2;
    ll elem = 3;
    while(1){
        if(n % elem == 0) return elem;
        elem += 2;
    }
    return -1;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll elem = find_element(n);
        if(n % (elem*elem) == 0) cout << elem << ' ' << n / (elem*elem) << endl;
        else cout << ll(sqrt(n / elem)) << ' ' << elem << endl;
    }
}