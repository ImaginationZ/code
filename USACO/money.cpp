/*
ID: frequen1
PROG: money
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

const int MAX = 1<<30;
const int V = 30;
const int N = 10005;

int coin[V];
int v;
long long ways[V][N] = {0};
int n;

ifstream fin ("money.in");
ofstream fout ("money.out");


int main(int argc, char *argv[])
{
  fin >> v >> n;
  for (int i = 0; i < v; ++i)
    {
      fin >> coin[i];
    }
  sort(coin,coin+v);
  for (int i=0; i < v; ++i){
    ways[i][0] = 1;
    ways[i][coin[0]] = 1;
  }
for (int i = coin[0]+1; i <= n; ++i)
  {
    ways[0][i] = ways[0][i-coin[0]];
     for (int j = 1; j < v; ++j)
      {
        if(i >= coin[j])
          ways[j][i] = ways[j-1][i] + ways[j][i-coin[j]];
        else 
          ways[j][i] = ways[j-1][i];
      }
  }
 fout << ways[v-1][n] << endl;
 return 0;
}

