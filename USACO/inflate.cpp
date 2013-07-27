/*
ID: frequen1
PROG: inflate
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
#include <iomanip>
#include <utility>

using namespace std;

const int MAX = 1<<30;
const int M = 10001;
const int N = 10001;

int points[M] = {0};

int po[N];
int mi[N];

int m,n;

ifstream fin ("inflate.in");
ofstream fout ("inflate.out");


int main(int argc, char *argv[])
{
  fin >> m >> n;
  for (int i = 1; i <= n; ++i)
	{
	  fin >> po[i] >> mi[i];
	}
  for (int i = 1; i <= n; ++i)
	{
    for (int j = 1; j <= m; ++j)
	  {
		if(j >= mi[i])
		  if( po[i] + points[ j - mi[i] ] > points[j])
			points[j] = po[i] + points[ j -  mi[i] ];
	  }
	}
  fout << points[m] << endl;
  return 0;
}

