#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<int, bool> judge_pass(int max_num, vector<pair<int, int>> &subject, map<int, bool> &pass){
    int cnt;
    cnt = 0;
    for(auto iter: subject){
        if(cnt == max_num) break;
        if(!pass.at(iter.second)){
            pass.at(iter.second) = true;
            cnt++;
        }
    }
    return pass;
}

int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<pair<int, int>> math, eng, sum;
    map<int, bool> pass;
    for(int i=0; i<n; i++){
        int score;
        cin >> score;
        math.push_back(make_pair(-score, i));
    }
    for(int i=0; i<n; i++){
        int score;
        cin >> score;
        eng.push_back(make_pair(-score, i));
    }
    for(int i=0; i<n; i++){
        int score=math.at(i).first + eng.at(i).first;
        sum.push_back(make_pair(score, i));
    }
    for(int i=0; i<n; i++) pass[i] = false;

    sort(math.begin(), math.end());
    sort(eng.begin(), eng.end());
    sort(sum.begin(), sum.end());

    pass = judge_pass(x, math, pass);
    pass = judge_pass(y, eng, pass);
    pass = judge_pass(z, sum, pass);

    for(int i=0; i<n; i++){
        if(pass.at(i)) cout << i+1 << endl;
    }
}