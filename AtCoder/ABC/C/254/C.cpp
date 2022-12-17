#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), merg;
    vector<vector<int>> split(k);
    for(int i=0; i<n; i++) cin >> a.at(i);
    for(int i=0; i<n; i++) split.at(i%k).push_back(a.at(i));
    sort(a.begin(), a.end());
    for(int i=0; i<k; i++){
        sort(split.at(i).begin(), split.at(i).end());
    }
    for(int i=0; i<n; i++) merg.push_back(split.at(i%k).at(i/k));
    cout << (a == merg ? "Yes" : "No") << endl;
}