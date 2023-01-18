#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    string S;
    cin >> S;

    for (int i = 0; i < S.size(); i++) {
        ans += ((long long)S.at(i) - 64) * (long long)pow(26, (S.size() - (i + 1)));
    }
    cout << ans << endl;
}