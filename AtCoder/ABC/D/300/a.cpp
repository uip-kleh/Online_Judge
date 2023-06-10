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

vector<bool> calc_prime(ll N){
    vector<bool> isprime(N+1, true);
    isprime[0] = isprime[1] = 0;
    for(ll i=2; i<=N; ++i){
        if(!isprime[i]) continue;
        for(ll j=i*2; j<=N; j+=i){
            isprime[j] = false;
        }
    }
    return isprime;
}

int main(){
    ll N; cin >> N;

    // 素数を調べる
    ll MAX = 3e5;
    vector<bool> isprime = calc_prime(MAX);
    vector<ll> prime;
    rep(i, MAX){
        if(isprime[i]) prime.push_back(i);
    }
    // cout << prime.size() << endl;
    sort(all(prime));

    ll ans = 0;
    int n = prime.size();
    for(int i=0; i<n; i++){
        if(prime[i] * prime[i] > N) break;
        for(int j=i+1; j<n; j++){
            if(prime[i] * prime[i] * prime[j] > N) break;
            for(int k=j+1; k<n; k++){
                if(prime[i] * prime[i] * prime[j] * prime[k] > N) break;
                if(prime[i] * prime[i] * prime[j] * prime[k] * prime[k] > N) break;
                // cout << prime[i] << ' ' << prime[j] << ' ' << prime[k] << '=' << prime[i] * prime[i] * prime[j] * prime[k] * prime[k] << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;

}
