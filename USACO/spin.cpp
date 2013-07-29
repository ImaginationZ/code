/*
ID: frequen1
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <utility>
using namespace std;
const long oo = (1LL<<31)-1;
ifstream fin ("spin.in");
ofstream fout ("spin.out");

struct node{
  int begin;
  int extent;
  node(int x,int y):begin(x),extent(y){}
};
vector<node> wheel[5];
int speed[5];
int main(int argc, char *argv[])
{
  for (int i = 0; i < 5; ++i)
	{
	  fin >> speed[i];
	  int q,x,y;
	  fin >> q;
	  while(q--){
		fin >> x >> y;
		wheel[i].push_back(node(x,y));
	  }
	}
  int t;
  for (int i = 0; i < 5; ++i)
	{
	  for (int j = 0; j < wheel[i].size(); ++j)
		{
		  wheel[i][j].begin -= speed[i];
		}
	}
  for (t = 0; t < 360; ++t)
	{
	  int line[360] = {0};
	  for (int i = 0; i < 5; ++i)
		{
		  for (int j = 0; j < wheel[i].size(); ++j)
			{
			  wheel[i][j].begin += speed[i];
			  wheel[i][j].begin %= 360;
			  for (int p = wheel[i][j].begin; p <= wheel[i][j].begin + wheel[i][j].extent; ++p)
				{
				  line[p%360] ++;
				}
			}
		}
	  for (int i = 0; i < 360; ++i)
		{
		  if(line[i] == 5) {
			fout << t << endl;
			t = 361;
			break;
		  }
		}
	}
  if(t==360) fout <<"none"<<endl;
  return 0;
}

