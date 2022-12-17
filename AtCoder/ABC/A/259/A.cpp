#include<iostream>
using namespace std;

int main(){
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    cout << (m >= x ? t : t - (x - m) * d) << endl;
}