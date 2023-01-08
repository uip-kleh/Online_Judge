#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<string> v(n);
    for(int i=0; i<n; i++) cin >> v.at(i);
    for(int i=0; i<n; i++) cout << v.at(n-1-i) << endl;
}