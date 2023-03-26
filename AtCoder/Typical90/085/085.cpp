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

int main(){
    ll k; cin >> k;
    iv vec; 
    for(ll i=1; i*i<=k; i++){
        if(k % i != 0) continue;
        vec.push_back(i);
        if(i != k/i) vec.push_back(k/i);
    }
    // res.erase(unique(all(res)), res.end());
    sort(all(vec));
    ll ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i; j < vec.size(); j++) {
			long long a = vec[i], b = vec[j], c = 0;
			if ((k / a) < b) continue;
			if (k % (a * b) != 0LL) continue;
			c = k / (vec[i] * vec[j]);
			if (b <= c) ans += 1;
		}
	}
    cout << ans << endl;
}
