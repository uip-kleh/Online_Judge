#include<iostream>
#include<vector>
using namespace std;

int main(){
    int r, c; cin >> r >> c;
    vector<vector<int>> vvec(2, vector<int>(2));
    for(int j=0; j<2; j++){
        for(int i=0; i<2; i++){
            int n; cin >> n;
            vvec.at(j).at(i) = n; 
        }
    }
    cout << vvec.at(r-1).at(c-1) << endl;
}