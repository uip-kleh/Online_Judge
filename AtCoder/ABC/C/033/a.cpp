#include<iostream>
#include<vector>
#include<stack>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
typedef long long ll;
using namespace std;

int main(){
    string s; cin >> s;
    int n = s.length();

    stack<ll> stk;
    for(int i=0; i<n; i++){
        if(s[i] == '*'){
            i++;
            int v1 = stk.top(); stk.pop();
            int v2 = s[i] - '0';
            stk.push(v1 * v2);
        }
        else if(s[i] == '+') continue;
        else stk.push(s[i] - '0');
    }

    ll ans = 0;
    while(!stk.empty()){
        if(stk.top() != 0) ans++;
        stk.pop();
    }
    cout << ans << endl;
}
