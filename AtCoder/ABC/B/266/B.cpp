#include<iostream>
#include<algorithm>
#define MOD 998244353 
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    n %= MOD;
    if(n < 0) n += MOD;
    cout << n << endl;
}