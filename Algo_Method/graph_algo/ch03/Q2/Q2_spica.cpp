#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        G.at(A).push_back(B);
        G.at(B).push_back(A);
    }

    vector<int> dist(N, -1);
    vector<vector<int>> nodes(N);
    dist.at(0) = 0;
    nodes.at(0) = {0};

    for (int i = 1; i < N; ++i) {
        for (auto v : nodes.at(i - 1)) {
            for (auto next_v : G.at(v)) {
                if (dist.at(next_v) != -1) {
                    continue;
                }
                dist.at(next_v) = dist.at(v) + 1;
                nodes.at(i).push_back(next_v);
            }
        }
    }

    int max_d = 0;
    for (int i = 1; i < N; i++) {
        max_d = max(max_d, dist.at(i));
    }
    cout << max_d << endl;
}