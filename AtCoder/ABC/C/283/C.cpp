#include<iostream>  
using namespace std;

int main(){
    string s; cin >> s;
    int len = s.length(), cnt = 0;
    for(int i=0; i<len-1; i++){
        if(s.at(i) == '0' and s.at(i+1) == '0'){
            cnt++; i++;
        }
    }
    cout << len - cnt << endl;
}