#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, buf1 = 0, buf2 = 0;
    cin >> n;
    vector<int> c(n), p(n), cumulative_sum1(n + 1), cumulative_sum2(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> c.at(i) >> p.at(i);
    }
    cin >> q;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) {
        cin >> l.at(i) >> r.at(i);
    }
    
    cumulative_sum1.at(0) = buf1;
    cumulative_sum2.at(0) = buf2;
    for (int i = 1; i <= n; i++) {
        if (c.at(i - 1) == 1) {
            buf1 += p.at(i - 1);
        } else {
            buf2 += p.at(i - 1);
        }
        cumulative_sum1.at(i) = buf1;
        cumulative_sum2.at(i) = buf2;
    }

    for (int i = 0; i < q; i++) {
        cout << cumulative_sum1.at(r.at(i)) - cumulative_sum1.at(l.at(i) - 1) << " "
             << cumulative_sum2.at(r.at(i)) - cumulative_sum2.at(l.at(i) - 1) << endl;
    }

    return 0;
}
