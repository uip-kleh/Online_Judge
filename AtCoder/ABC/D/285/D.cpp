#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
#define SIZE 2e5
constexpr long long MOD = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef vector<ll> iv;
typedef vector<bool> bv;
typedef pair<ll, ll> ip;
typedef vector<ip> pv;
typedef vector<iv> ivv;
ll gcd(ll a, ll b){
    return b ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

bool is_prime(ll x){
    if(x < 2) return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(ll i=0; i<x; i++) if(x%i == 0) return 0;
    return 0;
}

ll digsum(ll n){
    ll res = 0;
    while(n > 0){
        res += n%10;
        n /= 10;
    }
    return res;
}

ll pow(ll x, ll n){
    ll ans = 1;
    while(n){
        if(n % 2) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<string> s(n), t(n);
    set<string> st;
    map<string, set<string>> mp;
    map<string, int> deg;
    for(int i=0; i<n; i++){
        cin >> s.at(i) >> t.at(i);
        mp[t.at(i)].insert(s.at(i));
        deg[s.at(i)]++;
        st.insert(s.at(i));
        st.insert(t.at(i));
    }

    queue<string> q;
    rep(i, n){
        if(deg[s.at(i)] == 0) q.push(s.at(i));
        if(deg[t.at(i)] == 0) q.push(t.at(i));
    }

    vector<string> order;
    while(!q.empty()){
        string s = q.front(); q.pop();
        order.push_back(s);
        for(auto news: mp[s]){
            deg.at(news)--;
            if(deg.at(news) == 0){
                q.push(news);
            }
        }
    }
    cout << (st.size() == order.size() ? "Yes" : "No") << endl;
}
