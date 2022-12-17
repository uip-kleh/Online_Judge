#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int s_size;
string s;
map<string, int> checked;
queue<string> q;

int main(){
    // INPUT 
    cin >> s;
    s_size = s.size();

    // INITIALIZE
    checked[s] = 0;
    q.push(s);

    // bfs
    while(!q.empty() && checked.find("atcoder") == checked.end()){
        s = q.front();
        q.pop();
        for(int i=1; i<s_size; i++){
            string new_s = s;
            new_s.at(i) = s.at(i-1);
            new_s.at(i-1) = s.at(i);
            if(checked.find(new_s) == checked.end()){
                q.push(new_s);
                checked[new_s] = checked[s] + 1;
            }
        }
    }
    cout << checked.at("atcoder") << endl;
}