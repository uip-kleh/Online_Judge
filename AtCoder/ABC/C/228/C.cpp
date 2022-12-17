#include<iostream>
#include<vector>
#include<algorithm>
#define SIZE 10e5 + 5
using namespace std;

int n, k, clear_score;
vector<bool> pass(SIZE, false);
vector<pair<int, int>> score;

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<3; j++){
            int p;
            cin >> p;
            sum += p;
        }
        score.push_back(make_pair(-sum, i));
    }
    sort(score.begin(), score.end());
    clear_score = score.at(k-1).first;
    /*
    for(int i=0; i<n; i++){
        cout << score.at(i).first << ' ' << score.at(i).second << endl;
    }
    */
    for(auto iter: score){
        if(abs(iter.first) >= abs(clear_score) - 300) pass.at(iter.second) = true;
    }
    for(int i=0; i<n; i++){
        cout << (pass[i] ? "Yes" : "No") << endl;
    }
}   