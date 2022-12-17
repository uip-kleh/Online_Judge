#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n, m;

void search(int pre, stack<int> &stk){
    // basecase
    if(stk.size() == n){
        stack<int> buf = stk;
        vector<int> ans;
        while(!buf.empty()){
            ans.push_back(buf.top());
            buf.pop();
        }
        for(int i=n-1; i>0; i--){
            cout << ans.at(i) << ' ';
        }
        cout << ans.at(0) << endl;
        return;
    }

    // step
    for(int i=pre+1; i<m+1; i++){
        stk.push(i);
        search(i, stk);
        stk.pop();
    }
}

int main(){
    cin >> n >> m;

    stack<int> stk;
    search(0, stk);
}