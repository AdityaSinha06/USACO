#include<bits/stdc++.h>
using namespace std;


int main() {

    freopen("cbarn.in" , "r" , stdin);
    freopen("cbarn.out" , "w" , stdout);

    int n; cin >> n;

    int sum = 0;
    vector<int> r(n+1);
    for(int i=1; i<=n; i++) {
        cin >> r[i];
        sum += r[i];
    }

    for(int i=1; i<=n; i++) r.push_back(r[i]);

    int minDist = 1e9;

    int currDist = 0 , currCnt = sum;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<i+n; j++) {
            currCnt -= r[j];
            currDist += (currCnt - r[j]);
        }

        minDist = min(minDist , currDist);
        currDist = 0;
        currCnt = sum;
    }

    cout << minDist;

    return 0;
}