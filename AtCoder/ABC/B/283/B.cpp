#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, q; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a.at(i);
    cin >> q;
    while(q--){
        int c; cin >> c;
        if(c == 1){
            int k, x; cin >> k >> x, k--;
            a.at(k) = x;
        }
        else{
            int k; cin >> k, k--;
            cout << a.at(k) << endl;
        }
    }
}