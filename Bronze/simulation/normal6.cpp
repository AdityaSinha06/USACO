// outputs : u + 1 lines :
// line1 : minimum num of operations req to reconstruct the canvas
// rest U lines : after each Uith update minimum operations required to reconstruct the canvas

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

int findCnt(vector<vector<char>>& grid , int n) {
    
    int opsCnt = 0;
    for(int i=1; i<=n/2; i++) {
        for(int j=1; j<=n/2; j++) {
            int paintCnt = 0;
            paintCnt += (grid[i][j] == '#');
            paintCnt += (grid[i][n-j+1] == '#');
            paintCnt += (grid[n-i+1][j] == '#');
            paintCnt += (grid[n-i+1][n-j+1] == '#');

            // paintCnt == 0 / 4 : 0 ops
            //          == 1 : unpaint painted : 1 op
            //          == 2 : paint other 2 : 2 op
            //          == 3 : paint 1 more : 1 op

            if(paintCnt == 1 || paintCnt == 3) ++opsCnt;
            else if(paintCnt == 2) opsCnt += 2;
        }
    }

    return opsCnt;

}

int main() {
    // setIO("");

    int n , u; cin >> n >> u;

    vector<vector<char>> grid(n+1 , vector<char>(n+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cin >> grid[i][j];
    }

    int minCnt = findCnt(grid , n);
    cout << minCnt << '\n';
    // cout << findCnt(grid , n) << '\n';
    
    // now , for each update need to calculate
    for(int i=1; i<=u; i++) {
        int r , c; cin >> r >> c;

        // newCnt = minCnt - cellContri + opsRed

        // int quadrant = 1;
        // if((r <= n/2) && (c > n/2)) quadrant = 2;
        // else if((r > n/2) && (c <= n/2)) quadrant = 3;
        // else quadrant = 4;

        int paintCnt = 0 , currContri = 0 , newContri = 0;
        paintCnt += (grid[r][c] == '#');
        paintCnt += (grid[r][n-c+1] == '#');
        paintCnt += (grid[n-r+1][c] == '#');
        paintCnt += (grid[n-r+1][n-c+1] == '#');

        if(paintCnt == 1 || paintCnt == 3) currContri = 1;
        else if(paintCnt == 2) currContri = 2;

        paintCnt = 0;

        grid[r][c] = ((grid[r][c] == '.') ? '#' : '.');

        paintCnt += (grid[r][c] == '#');
        paintCnt += (grid[r][n-c+1] == '#');
        paintCnt += (grid[n-r+1][c] == '#');
        paintCnt += (grid[n-r+1][n-c+1] == '#');

        if(paintCnt == 1 || paintCnt == 3) newContri = 1;
        else if(paintCnt == 2) newContri = 2;

        int newCnt = minCnt - currContri + newContri;
        minCnt = newCnt;

        cout << newCnt << '\n';
    }


    return 0;
}