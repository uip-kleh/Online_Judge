#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    int flag = -1;
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        if (S.at(i) == '"') {
            flag *= -1;
        }
        if (flag < 0 && S.at(i) == ',') {
            S.at(i) = '.';
        }
    }

    cout << S << endl;
}