#include<iostream>
#include<vector>
#define SIZE 100
using namespace std;

int n, cnt=0;
vector<int> a(SIZE);

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a.at(i);

    for(int i=0; i<n; i++){
        int pos=0;
        for(int j=i; j<n; j++){
            pos += a.at(j);
            if(pos >= 4){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}