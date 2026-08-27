#include <bits/stdc++.h>
using namespace std;


int main() {

    freopen("lostcow.in" , "r" , stdin);
    freopen("lostcow.out" , "w" , stdout);

    int x , y; cin >> x >> y;

    int change = 1;
    bool flag = true; // to flutuate + / -

    int currPosition = x , totalDist = 0;
    while(abs(currPosition - y) != 0) {
        int newPosition = x + change;
        if(!flag) newPosition = x - change;
        
        if((newPosition > y) && (x < y)) newPosition = y;
        else if((newPosition < y) && (x > y)) newPosition = y;

        totalDist += abs(newPosition - currPosition);
        
        change <<= 1;
        flag = !flag;
        currPosition = newPosition;
    }


    cout << totalDist;
    
    return 0;
}