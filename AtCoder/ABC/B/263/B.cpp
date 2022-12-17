#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n-1);
    for(int i=0; i<n-1; i++) cin >> p.at(i);

    int s = p.at(n-2), cnt = 1;
    while(s != 1){
        s = p.at(s-2);
        cnt++;
    }
    cout << cnt << endl;
}