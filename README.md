# 競技プログラムのアルゴリズム
参考にしたサイトとソースコード（主にC++）を記す。
```c++:
#define rep(i, n) for(ll i=0; i < ll(n); i++)
#define all(x) (x).begin(), (x).end()
ctypedef long long ll;
typedef vector<ll> iv;  // 一次元配列
typedef vector<iv> ivv; // 二次元配列
```

## [尺取り虫法](https://qiita.com/drken/items/ecd1a472d3a0e7db8dce)
- 条件を満たす区間のうち、最小・最大、数え上げ
- $O(N^2)$を$O(N)$で実装できる

# 探索
## [三部探索](https://qiita.com/ganyariya/items/1553ff2bf8d6d7789127)
- たかだか一つしか極値のない関数$f$bにおける極値を探索する

# 座標
## [座標圧縮](https://drken1215.hatenablog.com/entry/2021/08/09/235400)
- 配列のそれぞれの要素が、何番目に小さいかを求める
- 二分探索でおこなうため$O(\log{N})$
- vector内の重複要素を削除するプログラム
```c++:
iv buf = {2, 5, 1, 2, 4, 2, 10, 21, 3}
buf.erase(unique(all(buf)), buf.end()); // 重複要素を削除する
```

## マンハッタン距離の和
- 中央値で絶対値最小となる
- [STL](https://cpprefjp.github.io/reference/algorithm/nth_element.html)を使用
```c++:
nth_element(x.begin(), x.begin() + x.length() / 2, x.end());
median = x.at(x.length() / 2);  // 中央値
```

## 累積和アルゴリズム
## [いもす法](https://imoz.jp/algorithms/imos_method.html)
- 一次元、二次元の領域加算に用いる

## 動的計画法
- [多項式・形式的べき級数数え上げとの対応付け](https://maspypy.com/%E5%A4%9A%E9%A0%85%E5%BC%8F%E3%83%BB%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0%E6%95%B0%E3%81%88%E4%B8%8A%E3%81%92%E3%81%A8%E3%81%AE%E5%AF%BE%E5%BF%9C%E4%BB%98%E3%81%91)
    - 結構わかりやすい
    - 部分和問題を多項式の分配法則・状態遷移からアプローチ

## グラフ理論
### [木の最大安定集合](https://algo-method.com/tasks/978)
- どの2頂点も辺で結ばれていないようなもの
- DFSの帰りがけ順で、子頂点がひとつも選ばれていないければ選ぶ（貪欲法）
- [ソースコード](https://algo-method.com/submissions/888438)

### [木の最大マッチング](https://algo-method.com/tasks/979)
- 重複なく二つの頂点を選ぶときの最大値
- DFSの帰りがけ順で、頂点とその親が選ばれていないとき選ぶ（貪欲法）
- [ソースコード](https://algo-method.com/submissions/888449)

### [木の最小点被覆](https://algo-method.com/tasks/980)
- いくつかの頂点を選び、すべての辺をおおうときの頂点の最小個数
- DFSの帰りがけ順で、子頂点において選ばれていないものがあるとき選ぶ
- [ソースコード](https://algo-method.com/submissions/888453)

## 整数問題

### [整数の乗数に対する繰り返し二乗法](https://qiita.com/ophhdn/items/e6451ec5983939ecbc5b)
- $3^{50}$などを高速で計算できる。
- 乗数$O(N)$に対して$O(\log{N})$
```c++:
ll pow(ll x, ll n){
    ll ans = 1;
    while(n){
        if(n % 2) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}
```

### [行列の乗数に対する繰り返し二乗法](https://hcpc-hokudai.github.io/archive/algorithm_binary_001.pdf)
- 繰り返し二乗法を行列に応用
- $N \times N$行列の$k$乗に適用すると$O(N^{3} \log{k})$
    - 行列の積の計算が各要素で$O(N)$
    - 行列の要素は$N^{2}$より、$O(N^3)$
    - 繰り返し二乗法は$O(\log{k})$より$O(N^3 \log{k})$
```c++:
// 二次元配列の行列積演算
ivv mat_mul(ivv a, ivv b, ll mod){
    int n = a.size();
    ivv res(n, iv(n));
    rep(i, n){
        rep(j, n){
            rep(k, n){
                res.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
                res.at(i).at(j) %= mod;
            }
        }
    }
    return res;
}

// 繰り返し二乗法の適用
ivv mat_pow(ivv a, ll b, ll mod){
    int n = a.size();
    ivv res(n, iv(n));
    rep(i, n) res.at(i).at(i) = 1;
    while(b){
        if(b & 1) res = mat_mul(res, a, mod);
        a = mat_mul(a, a, mod);
        b >>= 1;
    }
    return res;
}
```

## セグメント木
- [理論（簡単）](https://zenn.dev/magurofly/articles/3aa1084dfecce2)
- [実装（難しい）](https://algo-logic.info/segment-tree/)
