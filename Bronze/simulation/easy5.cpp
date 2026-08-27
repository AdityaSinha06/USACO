#include<bits/stdc++.h>
using namespace std;


int main() {
    
    freopen("blist.in" , "r" , stdin);
    freopen("blist.out" , "w" , stdout);

    int n; cin >> n;

    // vector<int> s(n+1) , t(n+1) , b(n+1);
    // set<int> st;
    // for(int i=1; i<=n; i++) {
    //     cin >> s[i] >> t[i] >> b[i];
    //     st.insert(s[i]);
    //     st.insert(t[i]);
    // }

    // vector<int> intervals(st.begin() , st.end());
    // int maxBucketReq = 0;
    // for(int i=0; i<intervals.size() - 1; i++) {
    //     int l = intervals[i] , r = intervals[i+1];
    //     int currBucketReq = 0;
    //     for(int j=1; j<=n; j++) {
    //         int s1 = s[j] , t1 = t[j] , b1 = b[j];
    //         if(max(l , s1) < min(r , t1)) currBucketReq += b1;
    //     }

    //     if(currBucketReq > maxBucketReq) maxBucketReq = currBucketReq;
    // }

    // cout << maxBucketReq;


    vector<int> time(1001);
    for(int i=1; i<=n; i++) {
        int s , t , b; cin >> s >> t >> b;
        time[s] += b;
        time[t] -= b;
    }

    int maxBucketReq = 0 , currReq = 0;
    for(int i=1; i<=1000; i++) {
        currReq += time[i];

        if(currReq > maxBucketReq) maxBucketReq = currReq;
    }

    cout << maxBucketReq;

    return 0;
}