#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> vec;
    for(int i=0; i<n; i++){
        int l;
        cin >> l;
        vector<int> a(l);
        for(int j=0; j<l; j++){
            cin >> a.at(j);
        }    
        vec.push_back(a);
    }
    while(q--){
        int s, t;
        cin >> s >> t;
        cout << vec.at(s-1).at(t-1) << endl;
    }
}