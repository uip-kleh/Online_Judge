#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
//#define SIZE
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
    ll res=1; while(n--) res *= x;
    return res;
}

int main(){
    int n; cin >> n;
    ivv g(n+1);
    rep(i, n-1){
        int a, b; cin >> a >> b;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    int min_node = 1, min_size = g.at(1).size();
    for(int i=2; i<n+1; i++){
        if(min_size > g.at(i).size()){
            min_node = i;
            min_size = g.at(i).size();
        }
    }

    vector<int> ans1, ans2;
    ans1.push_back(min_node);
    unordered_map<int, int> checked;
    checked[min_node] = 0;
    queue<int> q; 
    q.push(min_node);
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto new_node: g.at(node)){
            if(checked.find(new_node) != checked.end()) continue;
            checked[new_node] = checked[node] + 1;
            if(checked[new_node] % 2 == 0) ans1.push_back(new_node);
            else ans2.push_back(new_node); 
            q.push(new_node);
        }
    }
   if(ans1.size() > ans2.size()){
        rep(i, n/2){
            cout << ans1.at(i);
            cout << (i == n/2-1 ? '\n' : ' '); 
        }    
   }
   else{
        rep(i, n/2){
            cout << ans2.at(i);
            cout << (i == n/2-1 ? '\n' : ' '); 
        } 
   }
}
