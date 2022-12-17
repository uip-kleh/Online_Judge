#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int q;
    cin >> q;
    multiset<int> mst;
    while(q--){
        int n;
        cin >> n;
        if(n == 1){
            int x;
            cin >> x;
            mst.insert(x);
        }
        if(n == 2){
            int x, c;
            cin >> x >> c;
            while(c-- && mst.find(x) != mst.end()){
                mst.erase(mst.find(x));
            }
        }
        if(n == 3){
            cout << *mst.rbegin() - *mst.begin() << endl;
        }
    }
}