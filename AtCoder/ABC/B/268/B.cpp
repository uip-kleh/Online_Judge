#include<iostream>
using namespace std;

int main(){
    // INPUT
    string s, t;
    cin >> s >> t;

    if(s.length() > t.length()){
        cout << "No" << endl;
    }
    else{
        for(int i=0; i<s.length(); i++){
            if(s.at(i) != t.at(i)){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }

}