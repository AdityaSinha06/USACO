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

int max(int a , int b) {
    if(a > b) return a;
    return b; 
}

int main() {
    setIO("censor");

    string s , t;

    cin >> s >> t;

    int idx = 0;
    while(true) {
        bool opPerformed = false;
        for(int i=idx; i<s.length(); i++) {
            if(s.substr(i , t.length()) == t) {
                opPerformed = true;
                s.erase(i , t.length());

                idx = max(0 , (i - (t.length() - 1)));
                break;
            }
        }

        if(!opPerformed) break;
    }

    cout << s;


    return 0;
}