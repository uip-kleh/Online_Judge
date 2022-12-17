#include<iostream>
#include<vector>
using namespace std;

int h, w;
vector<string> vec;
vector<pair<int, int>> pos;

int main(){
    cin >> h >> w;
    for(int j=0; j<h; j++){
        string s; cin >> s;
        vec.push_back(s);
    }
    for(int j=0; j<h; j++){
        for(int i=0; i<w; i++){
            if(vec.at(j).at(i) == 'o') pos.push_back(make_pair(i, j));
        }
    }
    cout << (abs(pos.at(0).first - pos.at(1).first) + abs(pos.at(0).second - pos.at(1).second)) << endl;
}