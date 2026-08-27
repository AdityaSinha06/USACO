#include<bits/stdc++.h>
using namespace std;

int main() {
    
    freopen("shuffle.in" , "r" , stdin);
    freopen("shuffle.out" , "w" , stdout);

    // int n; cin >> n;

    // vector<int> a(n+1);
    // for(int i=1; i<=n; i++) cin >> a[i];

    // vector<int> temp(n+1);
    // for(int i=1; i<=n; i++) temp[i] = i;

    // for(int i=1; i<=3; i++) {
    //     vector<int> currShuffle(n+1);
    //     for(int i=1; i<=n; i++) {
    //         currShuffle[a[i]] = temp[i];
    //     }

    //     temp = currShuffle;
    // }

    // vector<string> finalOrder(n+1);
    // for(int i=1; i<=n; i++) cin >> finalOrder[i];
    
    // vector<string> ans(n+1);
    // for(int i=1; i<=n; i++) {
    //     ans[temp[i]] = finalOrder[i];
    // }

    // for(int i=1; i<=n; i++) cout << ans[i] << '\n';

    int n; cin >> n;

    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    vector<int> finalOrder(n+1);
    for(int i=1; i<=n; i++) cin >> finalOrder[i];

    for(int i=1; i<=3; i++) {
        vector<int> prevOrder(n+1);
        for(int i=1; i<=n; i++) {
            prevOrder[i] = finalOrder[a[i]];
        }
        
        finalOrder = prevOrder;
    }

    for(int i=1; i<=n; i++) cout << finalOrder[i] << '\n';


    return 0;
}