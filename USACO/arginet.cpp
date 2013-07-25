/*
ID: frequen1
PROG: agrinet
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
const int N = 105;
int n;

int adj[N][N];
bool mark[N] = {0};
int dis[N];

ifstream fin ("agrinet.in");
ofstream fout ("agrinet.out");


int main(int argc, char *argv[])
{
  fin >> n;
  for (int i = 0; i < n; ++i)
	{
	  for (int j = 0; j < n; ++j)
		{
		  fin >> adj[i][j];
		}
	  dis[i] = MAX;
	}
  dis[0] = 0;
  int p = n;
  int sum = 0;
  while(true){
	int min = MAX;
	p = n;
	for (int i = 0; i < n; ++i)
	  {
		if(!mark[i])
		  if(min > dis[i])
			{
			  min = dis[i];
			  p = i;
			}
	  }
	if( p == n ) break;
	mark[p] = 1;
	for (int i = 0; i < n; ++i)
	  {
		dis[i] = adj[i][p];
	  }
	sum += min;
  }
  fout << sum << endl;
	
  return 0;
}

