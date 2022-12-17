#include<iostream>
#include<vector>
#define SIZE 3
using namespace std;

int cnt=0;
vector<int> h(SIZE), w(SIZE);

int main(){
    for(int i=0; i<3; i++) cin >> h.at(i);
    for(int i=0; i<3; i++) cin >> w.at(i);

    /*
    m11, m12, m13
    m21, m22, m23
    m31, m32, m33
    */
   for(int m11=1; m11<min(h.at(0), w.at(0)); m11++){
    for(int m12=1; m12<min(h.at(0), w.at(1)); m12++){
        for(int m21=1; m21<min(h.at(1), w.at(0)); m21++){
            for(int m22=1; m22<min(h.at(1), w.at(1)); m22++){
                int m13 = h.at(0) - m11 - m12;
                int m23 = h.at(1) - m21 - m22;
                int m31 = w.at(0) - m11 - m21;
                int m32 = w.at(1) - m12 - m22;
                int m33h = h.at(2) - m31 - m32;
                int m33w = w.at(2) - m13 - m23;
                if(m13 > 0 && m23 > 0 && m31 > 0 && m32 > 0 && m33h > 0 && m33w > 0 && m33h == m33w) cnt++;
            }
        }
    }
   }
   cout << cnt << endl;
}