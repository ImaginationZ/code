/*
ID: frequen1
PROG: concom
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
const int N = 105;

int conq[N][N];
int share[N][N];
bool control[N][N] = {0};
bool setted[N][N] = {0};
int n;

ifstream fin ("concom.in");
ofstream fout ("concom.out");

int renew( int x ){
  int t = 0;
  for (int i = 1; i < N; ++i)
    {
      if(!control[x][i] && conq[x][i] >= 50){
        control[x][i] = 1;
        ++ t;
        for (int j = 1; j < N; ++j)
          {
              conq[x][j] += share[i][j]; 
          }
      }
    }
  return t;
}


int main(int argc, char *argv[])
{
  fin >> n;
  for (int i = 1; i <= n; ++i)
    {
      int a,b,c;
      fin >> a >> b >> c;
      conq[a][b] = share[a][b] = c;
    }
  for (int i = 1; i < N; ++i)
    {
      control[i][i] = 1;
    }
  int sum;
  do
    {
      sum = 0;
      for (int i = 1; i < N; ++i)
        {
          sum += renew(i);
        }
    } while (sum);
  for (int i = 1; i < N; ++i)
    {
      for (int j = 1; j < N; ++j)
        {
          if (i!=j && control[i][j])
            {
              fout << i << ' ' << j << endl;
            }
        }
    }
  return 0;
}

