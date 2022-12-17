#include<iostream>
using namespace std;

int n, res=1;

int main(){
    cin >> n;
    while(n--){
        res *= 2;
    }
    cout << res << endl;
}