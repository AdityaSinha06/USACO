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
    setIO("");

    int n; cin >> n;

    vector<int> x(n+1) , y(n+1);
    for(int i=1; i<=n; i++) cin >> x[i];
    for(int i=1; i<=n; i++) cin >> y[i];

    int mxDist = 0;
    
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            pair<int , int> a = {x[i] , y[i]};
            pair<int , int> b = {x[j] , y[j]};

            int dist = pow((a.first - b.first) , 2) + pow((a.second - b.second) , 2);
            if(dist > mxDist) mxDist = dist;
        }
    }

    cout << mxDist;

    return 0;
}