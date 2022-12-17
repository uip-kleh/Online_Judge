#include<iostream>
#include<vector>
using namespace std;

vector<pair<char, int>> analy_str(string &str){
    vector<pair<char, int>> pvec;
    int cnt = 0;
    char pre_c = str.at(0);
    for(auto c: str){
        if(pre_c == c) cnt++;
        else{
            pvec.push_back(make_pair(pre_c, cnt));
            pre_c = c;
            cnt = 1;
        }
    }    

    return pvec;
}

int main(){
    string s, t;
    cin >> s >> t;
    s += " ";
    t += " ";
    vector<pair<char, int>> cnt_s, cnt_t;
    cnt_s = analy_str(s);
    cnt_t = analy_str(t);

    bool can_make = true;
    if(cnt_s.size() != cnt_t.size()) can_make = false;
    else{   
        for(int i=0; i<cnt_s.size(); i++){
            if(cnt_s.at(i).first != cnt_t.at(i).first) can_make = false;
            if(cnt_s.at(i).second == 1 && cnt_s.at(i).second != cnt_t.at(i).second) can_make = false;
            if(cnt_s.at(i).second > 1 && cnt_s.at(i).second > cnt_t.at(i).second) can_make = false;
        }
    }
    cout << (can_make ? "Yes" : "No") << endl;
}