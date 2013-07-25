/*
ID: frequen1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

const int N=50;
int n;

int way[N][900];

ofstream fout ("subset.out");
ifstream fin ("subset.in");


int main(int argc, char *argv[])
{
  fin >> n;
  way[1][1] = 1;
  for (int i = 1; i <= n; ++i)
    {
      for (int n = 0; n <= i*(i+1)/2; ++n)
        {
          if(n>0){
            way[i+1][n+i+1] += way[i][n];
            if(n-i-1>=0) way[i+1][n-i-1] += way[i][n];
            else way[i+1][i+1-n] += way[i][n];
          }
          else way[i+1][i+1] += 2 * way[i][0];
        }
    }
  fout << way[n][0] << endl;
  return 0;
}
