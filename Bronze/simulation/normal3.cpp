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
    setIO("blocks");

    int n; cin >> n;

    vector<int> freqCnt(26);
    for(int i=1; i<=n; i++) {
        string s; cin >> s;
        unordered_map<int , int> mpp1;

        for(auto &ch : s) mpp1[ch - 'a']++;

        cin >> s;
        unordered_map<int, int> mpp2;
        for(auto &ch : s) mpp2[ch - 'a']++;

        for(int i=0; i<26; i++) {
            freqCnt[i] += max(mpp1[i] , mpp2[i]);
        }
    }


    for(int i=0; i<26; i++) cout << freqCnt[i] << '\n';


    return 0;
}