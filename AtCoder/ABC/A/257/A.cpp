#include<iostream>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    string s;
    for(int i=0; i<26; i++){
        for(int j=0; j<n; j++){
            s += char(i + 'A');
        }
    }
    cout << s.at(x - 1) << endl;
}