/*
ID: frequen1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

const int N = 205;
const int K = 105;
const int mod = 9901;

int ways[N][K] = {0};
int n,k;

ifstream fin ("nocows.in");
ofstream fout ("nocows.out");


int main(int argc, char *argv[])
{
  fin >> n >> k;
  ways[1][1] = 1;
  ways[0][0] = 0;
  for (int i = 3; i <= n; ++i)
    {
      for (int j = 0; j <= k; ++j)
        {
          for (int nn = i-1; nn >= 0; --nn)
            {
              int h1;
              int h2 = j-1;
             for (h1 = h2 - 1; h1 >= 0; --h1)
               {
                 if(h2 > i - 1 - nn) break;
                 ways[i][j] += ways[nn][h1]*ways[i-1-nn][h2];
                 ways[i][j] %= mod;
               } 
             h1 = j-1;
             for (h2 = h1 - 1; h2 >= 0; --h2)
               {
                 if(h1 > nn) break;
                 ways[i][j] += ways[nn][h1]*ways[i-1-nn][h2];
                 ways[i][j] %= mod;
               }
             ways[i][j] += ways[nn][j-1]*ways[i-1-nn][j-1];
             ways[i][j] %= mod;
            }
          //          cout << i << ' '<<j<<' '<<ways[i][j] << endl;
        }
    }
  fout << ways[n][k] << endl;
  return 0;
}

