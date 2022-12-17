#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

ll need(ll n, ll a, ll b){
    return a * n + b * to_string(n).size();
}

int main(){
    ll a, b, x;
    cin >> a >> b >> x;

    ll l = 0, r = 10e8+1;
    while(r - l > 1){
        ll mid = (l + r) / 2;
        ll mid_val = need(mid, a, b);
        if(mid_val > x) r = mid;
        else l = mid;
    }
    cout << l << endl;
}