#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int main() {
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out"); 

    int m , n , k; fin >> m >> n >> k;

    vector<string> grid(m);

    for(int i=0; i<m; i++) {
        string s; fin >> s;
        grid[i] = s;
    }

    // expand k times in every direction
    // so row , wise each row will be printed k times

    // : each row will be printed k times , each col will be printed k times , continuously

    for(int i=0; i<m; i++) {
        string curr = grid[i];

        string newCurr = "";
        for(auto ch : curr) {
            // newCurr.append(k , ch);
            for(int cnt=1; cnt<=k; cnt++) newCurr.push_back(ch);
        }

        for(int cnt=1; cnt<=k; cnt++) fout << newCurr << '\n';
    }

    return 0;
}