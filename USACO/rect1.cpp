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
}rec[2000];

int colorsum[3000] = {0};

vector<int> action[10005];

ifstream fin ("rect1.in");
ofstream fout ("rect1.out");

int A,B,N;

vector< pair<int,int> > lastcount;

void countline(set<int> lineact){
  multimap<int,int> line;
  for (set<int>::iterator itr = lineact.begin(); itr != lineact.end(); ++itr){
	line.insert(pair<int,int>(rec[*itr].x1,*itr));
	line.insert(pair<int,int>(rec[*itr].x2,*itr));
  }
  line.insert(pair<int,int>(A,0));
  int last = 0;
  set<int> pool;
  pool.insert(0);
  for(multimap<int,int>::iterator itr = line.begin(); itr != line.end(); ++itr){
	colorsum[rec[*(pool.rbegin())].c] += itr->first-last;
	lastcount.push_back(pair<int,int> (rec[*(pool.rbegin())].c, itr->first-last));
	int now = itr->second;
	if( pool.find(now) == pool.end())
	  pool.insert(now);
	else
	  pool.erase(now);
	last = itr->first;
  }
}

int main(int argc, char *argv[])
{
  fin >> A >> B >> N;
  rec[0].x1 = 0;
  rec[0].x2 = A;
  rec[0].c = 1;
  for (int i = 1; i <= N; ++i)
	{
	  int xl,yl,xr,yr,color;
	  fin >> xl >> yl >> xr >> yr >> color;
	  action[yl].push_back(i);
	  action[yr].push_back(i);
	  rec[i].x1 = xl;
	  rec[i].x2 = xr;
	  rec[i].c = color;
	}
  /*  for (int i = 0; i < B; ++i)
	{
	  for (set<int>::iterator itr = action[i].begin(); itr != action[i].end(); itr++)
		{
		  if (action[i+1].find(*itr) != action[i+1].end())
			{
			  action[i+1].erase(*itr);
			}
		  else action[i+1].insert(*itr);
		}
	}
  */
  set<int> lineact;
  for (int i = 0; i < B; ++i)
	{
	  bool flag = 0;
	  for (vector<int>::iterator itr = action[i].begin(); itr != action[i].end(); ++itr )
		{
		  flag = 1;
		  if(lineact.find(*itr) != lineact.end())
			lineact.erase(*itr);
		  else lineact.insert(*itr);
		}
	  if(i==0 || flag)
		{
		lastcount.clear();
		countline(lineact);
		}
	  else
		for (vector< pair<int,int> >::iterator itr = lastcount.begin(); itr != lastcount.end(); ++itr )
		  colorsum[itr->first] += itr->second;
	}
  for (int i = 1; i < 2555; ++i)
	if( colorsum[i] )
	  {
		fout << i << ' ' << colorsum[i] << endl;
	  }
  return 0;
}

