#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> vec;

int main(){
    cin >> n;
    cout << 1 << endl;

    vec.push_back(1);
    for(int i=0; i<n-1; i++){
        vector<int> buf;
        buf.push_back(1);
        for(int j=0; j<i; j++){
            buf.push_back(vec.at(j) + vec.at(j+1));
        }
        buf.push_back(1);
        vec = buf;
        for(int j=0; j<i+1; j++){
            cout << vec.at(j) << ' ';
        }
        cout << vec.at(i+1) << endl;
    }
}   