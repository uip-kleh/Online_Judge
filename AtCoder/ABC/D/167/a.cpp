#include<bits/stdc++.h>
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define nrep(i, n) for(ll i=1; i<ll(n+1); i++)
#define rrep(i, n) for(ll i=ll(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define SIZE 2e5
#define INF 2e18
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
iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

struct edge {
    int from, to, length;
};

int main(){
    // INPUT
    int N;
    ll K;
    cin >> N >> K;
    iv A(N); rep(i, N) cin >> A[i], --A[i];

    int now = 0;
    set<int> st;
    iv path;
    while(st.find(now) == st.end()){
        path.push_back(now);
        st.insert(now);
        now = A[now];
    }

    int res = 1;
    rrep(i, path.size()){
        if(path[i] == now) break;
        res++;
    }
    int s = find(path.begin(), path.end(), now) - path.begin();  // s: ループする最初の部分に到達するまで
    int r = (int)path.size() - s;                                // 周期
    if (K < s) {  // ループ部分に到達しない時
        cout << path[K] + 1 << endl;
        return 0;
    } else {  // ループ部分に到達する時
        cout << path[(K - s) % r + s] + 1 << endl;
        return 0;
    }

    // disp
    // for(auto v: path) cout << v << ' ';
    // cout << endl;
    // cout << now << endl;
}
