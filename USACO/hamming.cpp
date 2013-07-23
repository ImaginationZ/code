/*
ID: frequen1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

const int MAX = 1 << 10;

int out[MAX];
int idx;

int n,b,d;
int limit;

bool test(int x,int y){
  x = x & limit;
  y = y & limit;
  int in = x ^ y;
  int ans = 0;
  while(in > 0){
    in -= in & (-in);
    ans++;
  }
  return (ans >= d);
}

int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    fin >> n >> b >> d;
    limit = (1<<b)-1;
    idx = 0;
    for (int i = 0; i < (1u << b); ++i)
      {
        int p=0;
        for(;p<idx;++p){
          if(!test(i,out[p]))
             break;
        }
        if(p==idx)
          out[idx++] = i;
      }
    for (int i = 0; i < n; ++i)
      {
        if(i==n-1) fout << out[i];
        else if ((i+1)%10) fout << out[i] << ' ';
        else fout << out[i] << endl;
      }
    fout << endl;
    return 0;
}
