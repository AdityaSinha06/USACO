#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

void setIO(string name = "") {
    FAST_IO;
    if (name != "") {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("mowing");

    // {coordinates , timeStamp}
    map<pair<int , int> , int> mpp;

    int n; cin >> n;

    int timeStamp = 0;
    int x = 0 , y = 0;

    int ans = 1e9;

    for(int i=1; i<=n; i++) {
        char D;
        int S;
        
        cin >> D >> S;

        for(int j=1; j<=S; j++) {
            ++timeStamp;
            if(D == 'N') {
                ++y;
            } else if(D == 'S') {
                --y;
            } else if(D == 'E') {
                ++x;
            } else {
                --x;
            }
            
            auto it = mpp.find({x , y});
            
            if(it != mpp.end()) {
                ans = min(ans , timeStamp - it->second);
                it->second = timeStamp;
            } else {
                mpp[{x , y}] = timeStamp;
            }
        }

    }

    cout << ((ans == 1e9) ? -1 : ans);

    return 0;
}