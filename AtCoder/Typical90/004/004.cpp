#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<int> hsum(h, 0), wsum(w, 0);
    vector<vector<int>> a(h, vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a.at(i).at(j);
            hsum.at(i) += a.at(i).at(j);
            wsum.at(j) += a.at(i).at(j);
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << hsum.at(i) + wsum.at(j) - a.at(i).at(j);
            if(j != w-1) cout << ' ';
            else cout << endl;
        }
    }

}