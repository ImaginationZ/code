/*
ID: frequen1
PROG: comehome
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

ifstream fin ("comehome.in");
ofstream fout ("comehome.out");

const int N = 100;

int dis[N];
bool mark[N] = {0};

int weight[N][N] = {0};

int toint(char c){
  if(c>='a' && c <= 'z') return c - 'a';
  else return c - 'A' + 26;
}

char tochar(int i){
  if ( i >= 0 & i < 26) return 'a'+i;
  return 'A' + i - 26;
}

int main(int argc, char *argv[])
{
  int n;
  fin >> n;
  for (int i = 0; i < N; ++i)
	{
	  for (int j = 0; j < N; ++j)
		{
		  weight[i][j] = MAX;
		}
	}
  while(n--){
	char x,y;
	int w;
	fin >> x >> y >> w;
	if(weight[toint(x)][toint(y)] > w)
	  weight[toint(x)][toint(y)] = weight[toint(y)][toint(x)] = w;
  }
  for (int i = 0; i < 51; ++i)
	{
	  dis[i] = MAX;
	}
  dis[51] = 0;
  int p;
  while(true){
	int min = MAX;
	p = 52;
	for (int i = 0; i < 52; ++i)
	  {
		if(!mark[i])
		  if(dis[i] < min)
			{
			  min = dis[i];
			  p = i;
			}
	  }
	if(p == 52) break;
	mark[p] = 1;
	if( p >= 26 && p < 51 ) break;
	for (int i = 0; i < 52; ++i)
	  {
		if (dis[i] > dis[p] + weight[i][p])
		  dis[i] = dis[p] + weight[i][p];
	  }
  }
  	fout << tochar(p) << ' '<< dis[p] << endl;

  return 0;
}

