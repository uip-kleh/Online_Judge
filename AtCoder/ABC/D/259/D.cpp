#include<iostream>
#include<vector>
#define SIZE 3005
typedef long long ll;
using namespace std;

ll n, sx, sy, tx, ty;
bool can_goal=false;
vector<ll> x(SIZE), y(SIZE), r(SIZE), start, goal;
vector<bool> checked(SIZE, false);
vector<vector<ll>> G(SIZE);

ll distance(ll x1, ll y1, ll x2, ll y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool include_goal(ll i){
    bool can=false;
    for(auto g: goal){
        if(g == i) can = true;
    }
    return can;
}

void init_checked(){
    for(int i=0; i<n; i++) checked.at(i) = false;
}

void dfs(ll node){
    // basecase
    if(include_goal(node)){
        can_goal = true;
        return;
    }
    if(checked.at(node)) return;
    

    // step
    checked.at(node) = true;
    for(auto new_node: G.at(node)){
        dfs(new_node);
    }
}

int main(){
    // input
    cin >> n >> sx >> sy >> tx >> ty;
    for(int i=0; i<n; i++) cin >> x.at(i) >> y.at(i) >> r.at(i);

    // make graph
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll dlen = distance(x.at(i), y.at(i), x.at(j), y.at(j));
            if(dlen > (r[i]+r[j])*(r[i]+r[j]) || dlen < (r[i]-r[j])*(r[i]-r[j])) continue;
            G.at(i).push_back(j);
            G.at(j).push_back(i);
        }
    }
    for(int i=0; i<n; i++){
        ll dlen = distance(sx, sy, x.at(i), y.at(i));
        if(dlen == r.at(i) * r.at(i)) start.push_back(i);
    }
    for(int i=0; i<n; i++){
        ll dlen = distance(tx, ty, x.at(i), y.at(i));
        if(dlen == r.at(i) * r.at(i)) goal.push_back(i);
    }
    for(auto s: start){
        init_checked();
        dfs(s);
    }

    cout << (can_goal ? "Yes" : "No") << endl;
    /*
    // disp G
    cout << "--- disp G ---" << endl;
    for(int i=0; i<n; i++){
        for(auto n: G.at(i)){
            cout << n << ' ';
        }
        cout << endl;
    }
    cout << "--- start ---" << endl;
    for(auto s: start){
        cout << s << ' ';
    }
    cout << endl;
    cout << "--- goal ---" << endl;
    for(auto g: goal){
        cout << g << ' ';
    }
    cout << endl;
    */
}  