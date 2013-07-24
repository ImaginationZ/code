/*
ID:frequen1
PROG:numtri
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>


using namespace std;

const int MAX = 1500;
int R[MAX][MAX]={0};

int main(){

    ifstream fin ("numtri.in");
    ofstream fout ("numtri.out");

    int r;
    fin >> r;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=i;++j){
            fin >> R[i][j];
        }
    }
    for (int i=2;i<=r;++i){
        for (int j=1;j<=i;++j){
            R[i][j] += max(R[i-1][j],R[i-1][j-1]);
        }
    }
    int max = 0;
    for (int j=1;j<=r;++j){
        if(R[r][j] > max)
            max = R[r][j];
    }
    fout << max << endl;
    return 0;
}
