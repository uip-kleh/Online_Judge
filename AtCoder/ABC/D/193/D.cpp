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

ll score(map<ll, ll> scores, int n){
    ll sum = 0;
    scores[n]++;
    for(auto iter: scores) sum += iter.first * pow(10, iter.second);
    return sum;
}

int main(){
    int k; cin >> k;
    string s, t; cin >> s >> t;
    map<ll, ll> s_cards, t_cards, sum_cards;
    
    // INIT
    rep(i, 9){
        s_cards[i+1] = 0;
        t_cards[i+1] = 0;
        sum_cards[i+1] = k;
    }   

    rep(i, 4){
        s_cards[s.at(i) - '0']++;
        t_cards[t.at(i) - '0']++;
        sum_cards[s.at(i) - '0']--;
        sum_cards[t.at(i) - '0']--;
    }

    ll sum = (k * 9 - 8), cnt = 0;
    sum *= sum - 1;
    rep(i, 9){
        rep(j, 9){
            ll s_score = score(s_cards, i+1);
            ll t_socre = score(t_cards, j+1);
            if(s_score <= t_socre) continue;
            if(i == j){
                if(sum_cards.at(i+1) - 2 < 0) continue;
                cnt += sum_cards.at(i+1) * (sum_cards.at(i+1)-1);
            }
            else{
                if(sum_cards.at(i+1) - 1 < 0 or sum_cards.at(j+1) - 1 < 0) continue;
                cnt += sum_cards.at(i+1) * sum_cards.at(j+1);
            }
        }
    }
    cout << double(cnt) / double(sum) << endl;
}
