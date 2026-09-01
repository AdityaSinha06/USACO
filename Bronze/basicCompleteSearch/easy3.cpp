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
    // setIO("");


    int n; cin >> n;
    vector<int> p(n+1);
    for(int i=1; i<=n; i++) cin >> p[i];

    // [i , j] :: is one photo , all flowers in the range i to j inc. are in one photo
    int photosCnt = 0;
    
    for(int i=1; i<=n; i++) {
        int petalsCnt = 0;
        unordered_set<double> st;
        for(int j=i; j<=n; j++) { // each j corresponds to new range [i , j] : new photo
            petalsCnt += p[j];
            st.insert((p[j] * 1.0));

            double avgPetalCnt = petalsCnt / ((j - i + 1) * 1.0);
            if(st.count(avgPetalCnt)) ++photosCnt;
        }
    }

    cout << photosCnt;

    return 0;
}