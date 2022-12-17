#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<set>
using namespace std;

int n, s_size;
char cvec[3] = {'3', '5', '7'};
map<string, bool> checked;
queue<string> q;

void dfs(string s){
    // basecase
    if(checked.find(s) != checked.end()) return;
    if(s.size() > s_size) return;

    // step
    checked[s] = true;
    q.push(s);
    while(!q.size() == 0){
        string current_s = q.front();
        q.pop();
        for(auto c: cvec){
            dfs(current_s + c);
        }
    }
}

int main(){
    cin >> n;
    s_size = to_string(n).size();

    string s;
    for(auto c: cvec){
        q.push(s + c);
    }
    dfs(s);

    int cnt = 0;
    for(auto iter: checked){
        set<char> st;
        for(auto c: iter.first){
            st.insert(c);
        }
        if(st.size() == 3 && atoi(iter.first.c_str()) <= n){
            //cout << iter.first << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
}