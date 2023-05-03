#include<iostream>
using namespace std;

bool isPrime(int v){
    if(v == 1) return false;
    if(v == 2) return true;
    for(int i=2; i*i<=v; i++){
        if(v % i == 0) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;

    long long ans = 0;
    while(n--){
        int v; cin >> v;
        if(isPrime(v)) ans++;
    }
    cout << ans << endl;
}
