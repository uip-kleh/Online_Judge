#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec(3);

int main(){
    for(int i=0; i<3; i++) cin >> vec.at(i);
    int median = vec.at(1);
    sort(vec.begin(), vec.end());
    cout << (median == vec.at(1) ? "Yes" : "No") << endl;
}