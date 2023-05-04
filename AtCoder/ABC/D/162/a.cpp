#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; string S; cin >> n >> S;
    int r = 1, g = 2, b = 4, rgb = 7;
    vector<int> cnt(8), color(n);
    for(int i=0; i<n; i++){
        if(S[i] == 'R') S[i] = r;
        if(S[i] == 'G') S[i] = g;
        if(S[i] == 'B') S[i] = b;
    }

    long long ans = 0;
    for(int j=0; j<n; j++) {
        for(int k=j+1; k<n; k++) {
            if (S[j] == S[k]) continue;

            int Si = rgb - S[j] - S[k];
            ans += cnt[Si];

            int i = j - (k - j);
            if (0 <= i) {
                int msk = S[i] | S[j] | S[k];
                if (msk == rgb) ans--;
            }
        }

        cnt[S[j]]++;
    }
    cout << ans << endl;
}
