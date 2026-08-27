#include<bits/stdc++.h>
using namespace std;

int main() {

    freopen("traffic.in" , "r" , stdin);
    freopen("traffic.out" , "w" , stdout);

    int n; cin >> n;

    vector<string> type(n+1);
    vector<int> l(n+1) , r(n+1);

    int firstAbsIdx = -1 , lastAbsIdx = 101;
    for(int i=1; i<=n; i++) {
        cin >> type[i] >> l[i] >> r[i];
        if(type[i] == "none") {
            if(firstAbsIdx == -1) firstAbsIdx = i;
            lastAbsIdx = i;
        }
    }

    // prior Calculation : last absolute value --> undo all the changes
    // after Calculation : first absolute value --> do all the changes

    // cout << firstAbsIdx << " " << lastAbsIdx << '\n';

    int pL = l[lastAbsIdx] , pR = r[lastAbsIdx];
    for(int i=lastAbsIdx-1; i>=1; i--) {
        if(type[i] == "on") {
            pL = max(0 , pL - r[i]);
            pR = max(0 , pR - l[i]);
        } else if(type[i] == "off") {
            pL += l[i];
            pR += r[i];
        } else {
            pL = max(pL , l[i]);
            pR = min(pR , r[i]);
        }
    }

    int aL = l[firstAbsIdx] , aR = r[firstAbsIdx];
    for(int i=firstAbsIdx+1; i<=n; i++) {
        if(type[i] == "on") {
            aL += l[i];
            aR += r[i];
        } else if(type[i] == "off") {
            aL = max(0 , aL - r[i]);
            aR = max(0 , aR - l[i]);
        } else {
            aL = max(aL , l[i]);
            aR = min(aR , r[i]);
        }
    }

    cout << pL << " " << pR << '\n';
    cout << aL << " " << aR << '\n';


    return 0;
}