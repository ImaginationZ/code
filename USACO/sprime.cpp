/*
ID: frequen1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int  MAX = 100000;
int out[9][MAX]={0};
int idx[9]={0};

bool test(int p){
  if(p==1) return 0;
  for (int i = 2; i <= sqrt(p); ++i)
    {
      if(p % i == 0) return 0;
    }
  return 1;
}

int main() {
  out[1][0] = 2;
  idx[1] = 1;
  idx[0]=1;
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    for (int d = 1; d < 9; ++d)
      {
        for (int i = 0; i < idx[d-1]; ++i)
          {
            for (int c = 1; c <= 9; c += 2)
              {
                int p = out[d-1][i] * 10 + c;
                if(test(p)){
                  out[d][idx[d]++]=p;
                }
              }
          }
      }
    int d;
    fin >> d;
    for (int i = 0; i < idx[d]; ++i)
      {
        fout << out[d][i] << endl;
      }
   return 0;
}
