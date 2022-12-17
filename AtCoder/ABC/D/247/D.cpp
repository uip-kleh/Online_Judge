#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i < int(n); i++)
#define nrep(i, n) for(int i=1; i<int(n+1); i++)
#define rrep(i, n) for(int i=int(n)-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(), (x).begin()
//#define SIZE
using namespace std;
typedef long long ll;
typedef vector<int> iv;
typedef vector<bool> bv;
typedef vector<ll> lv;
typedef pair<int, int> ip;
typedef vector<ip> pv;
typedef vector<iv> ivv;
int gcd(ll a, ll b){
    return b ? gcd(b, a%b) : a;
}

int lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

bool is_prime(int x){
    if(x < 2) return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(int i=0; i<x; i++) if(x%i == 0) return 0;
    return 0;
}

int digsum(int n){
    int res = 0;
    while(n > 0){
        res += n%10;
        n /= 10;
    }
    return res;
}

ll pow(ll x, ll n){
    int res=1; while(n--) res *= x;
    return res;
}

int main(){
    int q;
    deque<pair<ll,ll>> dq;
    cin >> q;
    while(q--){
        int i;
        cin >> i;
        if(i == 1){
            ll x, c;
            cin >> x >> c;
            dq.push_front(make_pair(x, c));
        }
        else{
            ll c;
            ll cnt = 0;
            cin >> c;
            while(c != 0){
                // cout << dq.size() << endl;
                pair<ll, ll> back_pair = dq.back(); dq.pop_back();
                if(back_pair.second - c == 0){
                    cnt += back_pair.first * c;
                    c = 0;
                }
                else if(back_pair.second - c > 0){
                    back_pair.second -= c;
                    cnt += back_pair.first * c;
                    c = 0;
                    dq.push_back(back_pair);
                }
                else{
                    cnt += back_pair.first * back_pair.second;
                    c -= back_pair.second;
                }
            }
            cout << cnt << endl;
        }
    }

    return 0;
}