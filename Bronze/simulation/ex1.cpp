#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int f(vector<int> shells , vector<vector<int>>& operations , int initialPosition) {
    shells[initialPosition] = 1;

    int cnt = 0;
    for(auto & v : operations) {
        int a = v[0] , b = v[1] , g = v[2];

        swap(shells[a] , shells[b]);
        if(shells[g] == 1) ++cnt;
    }

    return cnt;
} 

int main() {

    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int n; fin >> n;

    int cnt = 0;
    vector<int> shells(4 , 0);

    // here , Im assuming the first guess is correct and the next guesses are a/c 1st one
    // what if , the first guess is incorrect

    // need to consider for all possible cases , means say if initially the ball is in 1st then simulate the entire process , 
    // similarly , for each simulate.

    // store the operations

    vector<vector<int>> operations;
    for(int i=1; i<=n; i++) {
        int a , b , g; fin >> a >> b >> g;
        operations.push_back({a , b , g});
    }

    fout << max({f(shells , operations , 1) , f(shells , operations , 2) , f(shells , operations , 3)});


    return 0;
}