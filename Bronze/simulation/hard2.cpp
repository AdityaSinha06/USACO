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
    setIO("measurement");

    int n; cin >> n;

    unordered_map<string , int> mpp = {
        {"Bessie" , 0} , 
        {"Elsie" , 1} ,
        {"Mildred" , 2}
    };

    vector<vector<int>> input;
    for(int i=1; i<=n; i++) {
        int day ; cin >> day;
        string cow; cin >> cow;
        string change; cin >> change;

        bool isChangePositive = (change[0] == '+');
        if(isChangePositive) input.push_back({day , mpp[cow] , stoi(change.substr(1))});
        else input.push_back({day , mpp[cow] , -1*stoi(change.substr(1))});
    }    

    sort(input.begin() , input.end() , [&](auto a , auto b) {
        return (a[0] < b[0]);
    });
    
    vector<int> cows = {7 , 7 , 7};
    int currMax = 7;
    string prevDisplay = "012";
    int displayChangeCnt = 0;

    for(int i=0; i<input.size(); i++) {
        int cow = input[i][1] , change = input[i][2];
        cows[cow] += change;

        currMax = max({cows[0] , cows[1] , cows[2]});

        string currDisplay = "";
        if(cows[0] == currMax) currDisplay += "0";
        if(cows[1] == currMax) currDisplay += "1";
        if(cows[2] == currMax) currDisplay += "2";

        if(currDisplay != prevDisplay) {
            ++displayChangeCnt;
            prevDisplay = currDisplay;
        }

    }

    cout << displayChangeCnt;

    return 0;
}