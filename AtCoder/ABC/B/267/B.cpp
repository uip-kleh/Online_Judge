#include<iostream>
#include<vector>
using namespace std;

bool is_standing(int index, vector<vector<int>> &pos){
    for(auto val: pos.at(index)){
        if(val == 1) return true;
    }
    return false;
}

int main(){
    // INPUT
    string s;
    cin >> s;   

    // MAKE POSITION
    vector<vector<int>> pos(7);
    int l=3, cnt=1, index=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<cnt; j++){
            pos.at(l + 2*j).push_back(s.at(index) - '0');
            index++;
        }
        cnt++;
        l--;
    }
    /*
    // DISPLAY POS
    for(vector<int> ppos: pos){
        for(auto val: ppos){
            cout << val << ' ' ;
        }
        cout << endl;
    }
    */

    // COMBINATION
    bool is_split=false;
    for(int i=0; i<7; i++){
        if(s.at(0) == '1') break;
        for(int j=i+1; j<7; j++){
            if(is_standing(i, pos) && is_standing(j, pos)){
                for(int k=i+1; k<j; k++){
                    if(!is_standing(k, pos)) is_split = true;
                }
            }
        }
    }

    cout << (is_split ? "Yes" : "No") << endl;
}