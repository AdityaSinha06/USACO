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
    setIO("diamond");

    int n , k; cin >> n >> k;

    if(n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> arr(n+1);
    for(int i=1; i<=n; i++)  cin >> arr[i];

    // my approach: sort the diamonds a/c to their size in asc order , then perform iteration similar to maxm consecutive ones , and kadane algo ,  take is : if the continuity breaks , when a stone of size diff > k encountered , move the stIdx to the first stone where condition is getting satisfied , to get the longest possible satisfying length

    // sort(arr.begin() , arr.end());

    // int maxLen = 1 , len = 1;
    // int currMinIdx = 1;

    // for(int i=2; i<=n; i++) {
    //     int currMaxIdx = i-1;

    //     if((abs(arr[i] - arr[currMaxIdx]) <= k) && (abs(arr[i] - arr[currMinIdx]) <= k)) {
    //         ++len;
    //         if(len > maxLen) maxLen = len;
    //     } else {
    //         while(abs(arr[i] - arr[currMinIdx]) > k) {
    //             ++currMinIdx;
    //         }
    //         len = i - currMinIdx + 1;
    //     }
    // }

    // cout << maxLen;

    // approach 2: official solution : considering each stone of size x as the minimum size for the longest required length , total no stones lying in the range : [x , x+k]

    int mxLen = 0;

    for(int i=1; i<=n; i++) {
        int len = 0;
        for(int j=1; j<=n; j++) {
            if((arr[j] >= arr[i]) && (arr[j] <= arr[i] + k)) ++len;
        }

        if(len > mxLen) mxLen = len;
    }

    cout << mxLen;

    return 0;
}