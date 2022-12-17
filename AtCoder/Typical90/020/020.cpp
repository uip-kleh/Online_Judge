#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, c, res=1; cin >> a >> b >> c;
    while(b--){
        res *= c;
    }
    cout << (a < res ? "Yes" : "No") << endl; 
}