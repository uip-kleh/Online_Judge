#include<iostream>
#include<map>
using namespace std;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    map<int, int> hash;
    for(int i=1; i<k+1; i++){
        int a;
        cin >> a;
        hash[i] = a;
    }
    while(q--){
        int l;
        cin >> l;
        if(hash[l] != n){
            bool next_to=false;
            for(auto iter: hash){
                if(iter.second == hash[l]+1) next_to = true;
            }
            if(!next_to) hash[l]++;
        }
    }
    int cnt=1;   
    for(auto iter: hash){
        if(cnt == k) cout << iter.second << endl;
        else cout << iter.second << ' ';
        cnt++;
    }
}