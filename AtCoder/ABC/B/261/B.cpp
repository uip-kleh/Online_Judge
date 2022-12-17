#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }

    bool is_correct = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                if(a.at(i).at(j) != a.at(j).at(i)) is_correct = false;
            }
            else{
                if(a.at(i).at(j) == 'W' && a.at(j).at(i) != 'L') is_correct = false;
                if(a.at(i).at(j) == 'L' && a.at(j).at(i) != 'W') is_correct = false;
                if(a.at(i).at(j) == 'D' && a.at(j).at(i) != 'D') is_correct = false;
            }
        }
    }
    cout << (is_correct ? "correct" : "incorrect") << endl;
}