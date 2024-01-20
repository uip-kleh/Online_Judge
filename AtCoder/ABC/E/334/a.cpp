#include<bits/stdc++.h>
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define uniq(v) sort(all(v));v.erase(unique(all(v)),end(v))
#define ll long long
#define iv vector<ll>
#define ivv vector<iv>
#define ip pair<ll, ll>
#define rep(i, n) for(ll i=0; i<(ll)n; i++)
#define nrep(i, n) for(ll i=1; i<(ll)n+1; i++)
#define rrep(i, n) for(ll i=n-1; i>=0; i--)
ll MOD = 998244353;
using namespace std;
// USEFUL FUNCTION
template<class T>bool chmax(T&a,const T&b){return (a<b)&&(a=b,true);}
template<class T>bool chmin(T&a,const T&b){return (a>b)&&(a=b,true);}
template<class T>void print(T&a){for(auto v: a) cout << v << ' '; cout << endl;}
// NUMERIC FUNCTION
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
map<ll, ll> numeric_component(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; i++) {
        if (N % i != 0) continue;
        while (N % i == 0) {res[i]++; N /= i;}
    }
    if (N != 1) res[N]++;
    return res;
}
// GRAPH FUNCTION
struct UnionFind {
    iv par, rank, siz, min_node;
    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}
    int root(int x) {
        if (par.at(x) == -1) return x;
        else return par.at(x) = root(par.at(x));
    }
    bool is_same(int x, int y) {return root(x) == root(y);}
    bool unite(int x, int y) {

        int rx = root(x), ry = root(y);
        if (is_same(x, y)) return false;
        if (siz.at(rx) < siz.at(ry)) swap(rx, ry);
        par.at(ry) = rx;
        if (rank.at(rx) == rank.at(ry)) rank.at(rx) += 1;
        siz.at(rx) += siz.at(ry);
        return true;
    }
};
// TREE FUNCTION
template<class Monoid> struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    // core member
    int N;
    Func OP;
    Monoid IDENTITY;
    // inner data
    int offset;
    vector<Monoid> dat;
    // constructor
    SegTree() {}
    SegTree(int n, const Func &op, const Monoid &identity) {
        init(n, op, identity);
    }
    SegTree(const vector<Monoid> &v, const Func &op, const Monoid &identity) {
        init((int)v.size(), op, identity);
        build(v);
    }
    void init(int n, const Func &op, const Monoid &identity) {
        N = n;
        OP = op;
        IDENTITY = identity;
        offset = 1;
        while (offset < N) offset *= 2;
        dat.assign(offset * 2, IDENTITY);
    }
    void init(const vector<Monoid> &v, const Func &op, const Monoid &identity) {
        init((int)v.size(), op, identity);
        build(v);
    }
    void build(const vector<Monoid> &v) {
        assert(N == (int)v.size());
        for (int i = 0; i < N; ++i) dat[i + offset] = v[i];
        for (int k = offset - 1; k > 0; --k) dat[k] = OP(dat[k*2], dat[k*2+1]);
    }
    int size() const {
        return N;
    }
    Monoid operator [] (int a) const { return dat[a + offset]; }

    // update A[a], a is 0-indexed, O(log N)
    void set(int a, const Monoid &v) {
        int k = a + offset;
        dat[k] = v;
        while (k >>= 1) dat[k] = OP(dat[k*2], dat[k*2+1]);
    }

    // get [a, b), a and b are 0-indexed, O(log N)
    Monoid prod(int a, int b) {
        Monoid vleft = IDENTITY, vright = IDENTITY;
        for (int left = a + offset, right = b + offset; left < right;
        left >>= 1, right >>= 1) {
            if (left & 1) vleft = OP(vleft, dat[left++]);
            if (right & 1) vright = OP(dat[--right], vright);
        }
        return OP(vleft, vright);
    }
    Monoid all_prod() { return dat[1]; }

    // get max r that f(get(l, r)) = True (0-indexed), O(log N)
    // f(IDENTITY) need to be True
    int max_right(const function<bool(Monoid)> f, int l = 0) {
        if (l == N) return N;
        l += offset;
        Monoid sum = IDENTITY;
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(OP(sum, dat[l]))) {
                while (l < offset) {
                    l = l * 2;
                    if (f(OP(sum, dat[l]))) {
                        sum = OP(sum, dat[l]);
                        ++l;
                    }
                }
                return l - offset;
            }
            sum = OP(sum, dat[l]);
            ++l;
        } while ((l & -l) != l);  // stop if l = 2^e
        return N;
    }

    // get min l that f(get(l, r)) = True (0-indexed), O(log N)
    // f(IDENTITY) need to be True
    int min_left(const function<bool(Monoid)> f, int r = -1) {
        if (r == 0) return 0;
        if (r == -1) r = N;
        r += offset;
        Monoid sum = IDENTITY;
        do {
            --r;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(OP(dat[r], sum))) {
                while (r < offset) {
                    r = r * 2 + 1;
                    if (f(OP(dat[r], sum))) {
                        sum = OP(dat[r], sum);
                        --r;
                    }
                }
                return r + 1 - offset;
            }
            sum = OP(dat[r], sum);
        } while ((r & -r) != r);
        return 0;
    }

    // debug
    friend ostream& operator << (ostream &s, const SegTree &seg) {
        for (int i = 0; i < seg.size(); ++i) {
            s << seg[i];
            if (i != seg.size()-1) s << " ";
        }
        return s;
    };
};
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
ll frac(ll ans, ll dots) {
    return (ans%MOD) * modinv(dots, MOD) % MOD;
}
// GRID
iv di = {-1, 0, 0, 1};
iv dj = {0, -1, 1, 0};
iv di8 = {-1, -1, -1, 0, 0, 1, 1, 1};
iv dj8 = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H); rep(i, H) cin >> S[i];

    UnionFind uf(H*W);
    rep(i, H) {
        rep(j, W) {
            if(S[i][j] == '.') continue;
            int hash1 = i * W + j;
            if(j+1 < W and S[i][j+1] == '#') {
                int hash2 = i * W + j + 1;
                uf.unite(hash1, hash2);
            }

            if(i+1 < H and S[i+1][j] == '#') {
                int hash2 = (i + 1) * W + j;
                uf.unite(hash1, hash2);
            }
        }
    }


    // 連結の個数
    ll cnt = 0;
    rep(i, H*W) {
        // cout << i/H << ' ' << i%W << endl;
        if(uf.par[i] == -1 and S[i/W][i%W] == '#') {
            cnt++;
        }
    }
    ll dots = 0;
    ll ans = 0;

    auto is_in = [&](int i, int j) -> bool {
        if(i < 0 or i >= H) return false;
        if(j < 0 or j >= W) return false;
        return true;
    };
    // cout << cnt << endl;
    rep(i, H) {
        rep(j, W) {
            if(S[i][j] == '#') continue;

            set<int> st;
            if(is_in(i-1, j) and S[i-1][j] == '#') st.insert(uf.root((i-1) * W + j));
            if(is_in(i+1, j) and S[i+1][j] == '#') st.insert(uf.root((i+1) * W + j));
            if(is_in(i, j-1) and S[i][j-1] == '#') st.insert(uf.root(i * W + j - 1));
            if(is_in(i, j+1) and S[i][j+1] == '#') st.insert(uf.root(i * W + j + 1));

            // cout << st.size() << ":";
            // cout << cnt - st.size() + 1 << endl;
            ans += cnt - st.size() + 1;

            dots++;
        }
    }

    cout << frac(ans, dots) << endl;
}
