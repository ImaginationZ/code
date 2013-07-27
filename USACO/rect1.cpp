/*
ID: frequen1
PROG: rect1
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
#include <set>
#include <map>

using namespace std;

const int MAX = 1<<30;

struct node{
  int x1;
  int x2;
  int c;
}rec[200];

int colorsum[3000] = {0};

set<int> action[10005];

ifstream fin ("rect1.in");
ofstream fout ("rect1.out");

int A,B,N;

int main(int argc, char *argv[])
{
  fin >> A >> B >> N;
  for (int i = 0; i < N; ++i)
	{
	  int xl,yl,xr,yr,color;
	  fin >> xl >> yl >> xr >> yr >> color;
	  action[yl].insert(i);
	  action[yr].insert(i);
	  rec[i].x1 = xl;
	  rec[i].x2 = xr;
	  rec[i].c = color;
	}
  for (int i = 0; i < B; ++i)
	{
	  for (set<int>::iterator itr = action[i].begin(); itr != action[i].end(); itr++)
		{
		  if (action[i+1].find(*itr))
			{
			  action[i+1].erase(*itr);
			}
		  else action[i+1].insert(*itr);
		}
	}
  for (int i = 0; i < B; ++i)
	{
	  multimap<int,int> pool;
	  for (set<int>::iterator itr = action[i].begin(); itr != action[i].en			 d(); itr++)
		{
		
		}
	}
  return 0;
}

