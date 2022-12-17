#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> m;
    while(n--){
        string s;
        cin >> s;
        if(!m.count(s)){
            m[s] = 0;
            cout << s << endl;
        }
        else{
            m.at(s)++;
            cout << s << '(' << m[s] << ')' << endl;
        }
    }
}