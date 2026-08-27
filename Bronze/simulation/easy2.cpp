#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int main() {

    // ifstream fin("speeding.in");
    // ofstream fout("speeding.out");

    freopen("speeding.in" , "r" , stdin);
    freopen("speeding.out" , "w" , stdout);

    int n , m; cin >> n >> m;
    
    vector<int> speedLimit(101) , actualSpeed(101); // speedLimit and actual Speed at each mile

    int sum = 0;
    for(int i=0; i<n; i++) { //storing limits at endpoints
        int n1 , s1; cin >> n1 >> s1;
        sum += n1;
        speedLimit[sum] = s1;
    }

    sum = 0;
    for(int i=0; i<m; i++) {  //storing bessie's actual speeds , at its own segment wise
        int m1 , s1; cin >> m1 >> s1;
        sum += m1;
        actualSpeed[sum] = s1;
    }

    int curr = speedLimit[100];
    for(int i=99; i>=1; i--) {//floating that limit to the entire segment or floating speedlimit segment wise
        if(speedLimit[i] == 0) speedLimit[i] = curr;
        else curr = speedLimit[i];
    }

    curr = actualSpeed[100];
    for(int i=99; i>=1; i--) {
        if(actualSpeed[i] == 0) actualSpeed[i] = curr;
        else curr = actualSpeed[i];
    }

    int maxOver = 0;
    for(int i=1; i<=100; i++) {
        maxOver = max(maxOver , actualSpeed[i] - speedLimit[i]);
    }

    cout << maxOver;

    return 0;
}