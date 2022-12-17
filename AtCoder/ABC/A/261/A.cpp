#include<iostream>
#include<algorithm>  
using namespace std;

int main(){
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    cout << max((min(r1, r2) - max(l1, l2)), 0) << endl;
}