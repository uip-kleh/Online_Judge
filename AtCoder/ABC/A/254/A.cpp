#include<iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    n %= 100;
    if(n < 10) cout << "0" + to_string(n) << endl;
    else cout << n << endl;
}