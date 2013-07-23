/*
ID: frequen1
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int full;
int ans;
int mark[14];
int d;

    ofstream fout ("checker.out");
    ifstream fin ("checker.in");

int print(int a) 
{
  switch (a)
    {
    case 1:
      return 1;
    case 2:
      return 2;
    case 4:
      return 3;
    case 8:
      return 4;
    case 16:
      return 5;
    case 32:
      return 6;
    case 64:
      return 7;
    case 128:
      return 8;
    case 256:
      return 9;
    case 512:
      return 10;
    case 1024:
      return 11;
    case 2048:
      return 12;
    case 4096:
      return 13;
    }
}

void dfs(int row, int ldiag, int rdiag, int deep){
  if( row != full){
    int pos = full & ~( row | ldiag | rdiag );
    while(pos){
      int p = pos & -pos;
      pos ^= p;
      if(ans < 3) mark[deep] = p;
      dfs(row + p, (ldiag + p)<<1, (rdiag+p)>>1, deep+1);
    }
  }
  else{
    ++ans;
    if(ans <= 3){
      for (int i = 1; i < d; ++i)
        {
          fout << print( mark[i] ) << ' ';
        }
      fout << print( mark[d] );
      fout << endl;
    }
  }
}

 
int main() {
    fin >> d;
    full = (1u << d) - 1;
    ans = 0;
    dfs(0,0,0,1);
    fout << ans<< endl;


   return 0;
}
