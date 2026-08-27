#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    vector<int> capacity(4) , milk(4);
    for(int i=1; i<=3; i++) {
        int c , m; fin >> c >> m;
        capacity[i] = c;
        milk[i] = m;
    }

    int a = 1 , b = 2;

    for(int i=1; i<=4; i++) {
        if(a == 4) a = 1;
        if(b == 4) b = 1;

        int currAvail = milk[a] , nextLeft = capacity[b] - milk[b];
        int milkTransferred = min(currAvail , nextLeft);

        milk[a] -= milkTransferred;
        milk[b] += milkTransferred;

        a++;
        b++;
    }


    fout << milk[1] << '\n' << milk[2] << '\n' << milk[3];

    return 0;
}

// 1  2  3
// 10 11 12
// 3  4  5

// 1 : 3 , 7 , 3
// 0  7  5

// 2 : 7 7 , 7
// 0  0  12

// 3 : 12 , 10 , 10
// 10 0 2

// 4 : 10 , 11 , 10
// 0 , 10 , 2

// 5 : 10 , 10 , 10
// 0 , 0 , 12