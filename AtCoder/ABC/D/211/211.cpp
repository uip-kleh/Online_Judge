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

void disp_dp(ivv &dp){
    for(iv p: dp){
        for(auto v: p) cout << v << ' ';
        cout << endl;
    }
}
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

int main(){
    int n, m; cin >> n >> m;
    ivv g(n);
    rep(i, m){
        int a, b; cin >> a >> b, --a, --b;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    ll cnt = 0;
    queue<int> q; q.push(0);
    map<int, int> checked; checked[0] = 0;
    map<int, ll> ans; ans[0] = 1;
    ivv children(n);
    while(!q.empty()){
        int node=q.front(); q.pop();
        for(int new_node: g.at(node)){
            if(checked.find(new_node) != checked.end()){
                if(checked[node] + 1 == checked[new_node]){
                    ans[new_node] += ans[node];
                    ans[new_node] %= MOD;
                }
                continue;
            }
            checked[new_node] = checked[node] + 1;
            ans[new_node] += ans[node];
            ans[new_node] %= MOD;
            q.push(new_node);
        }
    }
    cout << ans[n-1] << endl;
}
