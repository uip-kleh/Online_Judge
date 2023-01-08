#include<iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, cnt = 0; cin >> n;
        for(int i=0; i<n; i++){
            int a; cin >> a;
            if(a % 2 == 1) cnt++;
        }
        cout << cnt << endl;
    }
}