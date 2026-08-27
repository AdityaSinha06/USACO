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

    vector<vector<int>> cows_north , cows_east;
    for(int i=1; i<=n; i++) {
        char dir;
        int x , y; 

        cin >> dir >> x >> y;
        if(dir == 'N') cows_north.push_back({x , y , i});
        else cows_east.push_back({x , y , i});
    }

    // simulating each time unit : will give a TLE
    // so , will go through all possible collisions
    // collisions are only possible bw cows moving right / east and cows moving up / north

    




    return 0;
}