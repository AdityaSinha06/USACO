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
    setIO("pails");

    // given a , b , c:
    // maximum sum <= c , we 're able to get using a and b

    // so , thinking greedily won't work , coz ' we're talking abt maximising sums
    // so , need to try out all possible combinations , meaning 
    // trying out all possible occurances of a and b giving sum upto c 

    int x , y , m; cin >> x >> y >> m;

    int maxX = m / x , maxY = m / y;

    int mxSum = 0;
    for(int i=0; i<=maxX; i++) {
        for(int j=0; j<=maxY; j++) {
            int sum = x * i + y * j;

            if(sum <= m) {
                if(sum > mxSum) mxSum = sum;
            }
        }
    }

    cout << mxSum;


    return 0;
}