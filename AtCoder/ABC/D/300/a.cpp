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
map<ll, ll> split(ll N){
    map<ll, ll> res;
    for(ll i=2; i*i<=N; i++){
        if(N % i != 0) continue;
        while(N % i == 0){
            res[i]++;
            N /= i;
        }
    }
    if(N != 1) res[N]++;
    return res;
}

iv dx = {-1, 0, 1, 0};
iv dy = {0, -1, 0, 1};

struct edge {
    int from, to, length;
};

bv Eratosthenes(ll n){
    bv isprime(n+1, true);

    isprime[0] = false;
    isprime[1] = false;
    for(int i=2; i<=n; i++){
        if(!isprime[i]) continue;
        for(int j=i*2; j<=n; j+=i){
            isprime[j] = false;
        }
    }
    return isprime;
}

int main(){
    ll n; cin >> n;

    ll MAX = 1e12 / 12;
    MAX = sqrt(MAX);
    // cout << MAX << endl;
    bv isprime = Eratosthenes(MAX);

    iv isPrime, times;
    rep(i, MAX){
        if(isprime[i]){
            isPrime.push_back(i);
            times.push_back(i*i);
        }
    }
    // cout << isPrime.size() << endl;

    ll siz = isPrime.size();
    ll ans = 0;
    rep(i, siz-2){
        for(int j=i+1; j<siz-1; j++){
            // cout << i << ' ' << j << endl;
            ll k = n / (isPrime[i] * isPrime[i] * isPrime[j]);
            if(isPrime[i] * isPrime[i] * isPrime[j] > n or isPrime[j] * isPrime[j] > k) break;
            // cout << isPrime[i] << ' ' << isPrime[j] << ' ' << k << endl;
            ans += lower_bound(all(times), k) - lower_bound(all(times), isPrime[j] * isPrime[j])  - 1;
        }
    }
    cout << ans << endl;
}
