/*
ID: frequen1
PROG: butter
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
ifstream fin ("butter.in");
ofstream fout ("butter.out");

int N,P,C;
int cow[505];
struct node
{
  int next;
  int w;
  node(int n,int pw):next(n),w(pw){}
};
struct nodecmp
{
  bool operator() (const node& x,const node& y) const
  {
	if(x.w==y.w) return x.next < y.next;
	return x.w > y.w;
  }
};
  
vector<node> path[805];
int shortest[805];
int cshortest[505][805];

int main(int argc, char *argv[])
{
  fin >> N >> P >> C;
  for (int i = 1; i <= N; ++i)
	{
	  fin >> cow[i];
	}
  for (int i = 0; i < 505; ++i)
	{
	  for (int j = 0; j < 805; ++j)
		{
		  cshortest[i][j] = oo;
		  shortest[j] = 0;
		}
	}
  while(C--)
	{
	  int i,j,w;
	  fin >> i >> j >> w;
	  path[i].push_back(node(j,w));
	  path[j].push_back(node(i,w));
	}
  for (int c = 1; c <= N; ++c)
	{
	  bool marked[805] = {0};
	  priority_queue<node,vector<node>,nodecmp> pool;
	  pool.push(node(cow[c],0));
	  while(pool.size()){
		int select = (pool.top()).next;
		marked[select] = 1;
		cshortest[c][select] = (pool.top()).w;
		for (int i = 0; i < path[select].size(); ++i)
		  {
			int to = path[select][i].next;
			int w = path[select][i].w;
			if( cshortest[c][select] + w < cshortest[c][to] ){
			  cshortest[c][to] =cshortest[c][select] + w;
			  pool.push(node(to,cshortest[c][to]));
			}
		  }
		while(pool.size() && marked[(pool.top()).next]) pool.pop();
	  }
	}
  for (int i = 1; i <= N; ++i)
	{
	  for (int j = 1; j <= P; ++j)
		{
		  shortest[j] += cshortest[i][j];
		}
	}
  int m = oo;
  for (int i = 1; i <= P; ++i)
	{
	  if(shortest[i] < m)
		{
		  m = shortest[i];
		}
	}
  fout << m << endl;
  return 0;
}

