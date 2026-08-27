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
    setIO("tttt");

    vector<vector<char>> grid(4 , vector<char>(4));

    for(int i=1; i<=3; i++) {
        string s; cin >> s;
        for(int j=1; j<=3; j++) {
            grid[i][j] = s[j-1];
        }
    }

    unordered_set<char> oneSt;

    if((grid[1][1] == grid[1][2]) && (grid[1][1] == grid[1][3])) oneSt.insert(grid[1][1]);
    if((grid[2][1] == grid[2][2]) && (grid[2][2] == grid[2][3])) oneSt.insert(grid[2][1]);
    if((grid[3][1] == grid[3][2]) && (grid[3][1] == grid[3][3])) oneSt.insert(grid[3][1]);

    if((grid[1][1] == grid[2][1]) && (grid[1][1] == grid[3][1])) oneSt.insert(grid[1][1]);
    if((grid[1][2] == grid[2][2]) && (grid[1][2] == grid[3][2])) oneSt.insert(grid[1][2]);
    if((grid[1][3] == grid[2][3]) && (grid[1][3] == grid[3][3])) oneSt.insert(grid[1][3]);

    if((grid[1][1] == grid[2][2]) && (grid[1][1] == grid[3][3])) oneSt.insert(grid[1][1]);
    if((grid[1][3] == grid[2][2]) && (grid[1][3] == grid[3][1])) oneSt.insert(grid[1][3]);


    int oneCnt = oneSt.size();

    // for team wins : for all possible wins : check distinct chars cnt , iff 2 : <min(ch1 , ch2) , max(ch1 , ch2)> form pair
    // for this not sure if set<pair<char , char>> works, acn use a 26 x 26 matrix

    vector<vector<int>> gridCnt(26 , vector<int>(26));

    // row-wise
    for(int i=1; i<=3; i++) {
        unordered_set<char> temp1 , temp2;
        for(int j=1; j<=3; j++) {
            temp1.insert(grid[i][j]);
            temp2.insert(grid[j][i]);
        }

        if(temp1.size() == 2) {
            auto it = temp1.begin();
            int i1 = *(it) - 'A';
            ++it;
            int i2 = *(it) - 'A';
            gridCnt[min(i1 , i2)][max(i1 , i2)]++;
        }

        if(temp2.size() == 2) {
            auto it = temp2.begin();
            int i1 = *(it) - 'A';
            ++it;
            int i2 = *(it) - 'A';
            gridCnt[min(i1 , i2)][max(i1 , i2)]++;
        }
    }

    int twoCnt = 0;
    unordered_set<char> temp3;

    for(int i=1; i<=3; i++) temp3.insert(grid[i][i]);
    
    if(temp3.size() == 2) {
        auto it = temp3.begin();
        int i1 = *(it) - 'A';
        ++it;
        int i2 = *(it) - 'A';
        gridCnt[min(i1 , i2)][max(i1 , i2)]++;
    }

    temp3.clear();

    for(int i=1; i<=3; i++) temp3.insert(grid[i][4 - i]);

    if(temp3.size() == 2) {
        auto it = temp3.begin();
        int i1 = *(it) - 'A';
        ++it;
        int i2 = *(it) - 'A';
        gridCnt[min(i1 , i2)][max(i1 , i2)]++;
    }

    for(int i=0; i<26; i++) {
        for(int j=0; j<26; j++) {
            if(gridCnt[i][j] > 0) ++twoCnt;
        }
    }

    cout << oneCnt << '\n' << twoCnt ;
    


    return 0;
}