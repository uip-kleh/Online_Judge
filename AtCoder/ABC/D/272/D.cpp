#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
//#define SIZE
using namespace std;
typedef long long ll;
typedef vector<ll> iv;
typedef vector<bool> bv;
typedef vector<ll> lv;
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

set<ip> generate_vector(int m){
    set<ip> v;
    for(int i=0; i * i < m + 1; i++){
        for(int j=0; j * j < m + 1; j++){
            if(i * i + j * j == m){
                v.insert(make_pair(i, j));
                v.insert(make_pair(-i, j));
                v.insert(make_pair(i, -j));
                v.insert(make_pair(-i, -j));
            }
        }
    }
    return v;
}

int main(){
    int n, m; cin >> n >> m;
    set<ip> v = generate_vector(m);
    map<ip, int> checked;
    queue<ip> q;
    ip node = make_pair(0, 0);
    checked[node] = 0;
    q.push(node);
    while(!q.empty()){
        node = q.front(); q.pop();
        for(auto iter: v){
            if(node.first + iter.first < 0 || node.first + iter.first >= n) continue;
            if(node.second + iter.second < 0 || node.second + iter.second >= n) continue;
            ip new_node = make_pair(node.first + iter.first, node.second + iter.second);
            if(checked.find(new_node) != checked.end()) continue;
            checked[new_node] = checked.at(node) + 1;
            q.push(new_node);
        }
    }
    rep(i, n){
        rep(j, n){
            ip node = make_pair(i, j);
            cout << (checked.find(node) == checked.end() ? -1 : checked.at(node));
            cout << (j == n - 1 ? '\n' : ' '); 
        }
    }
}
