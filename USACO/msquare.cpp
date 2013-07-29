/*
ID: frequen1
PROG: msquare
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
ifstream fin ("msquare.in");
ofstream fout ("msquare.out");

struct node{
  int num[8];
  int t;
  string p;
};
node origin;
node ter;
node A(node o){
  node ans;
  ans.t = o.t+1;
  ans.p = o.p + "A";
  for (int i = 0; i < 8; ++i)
	{
	  ans.num[i] = o.num[(i+4)%8];
	}
  return ans;
}
node B(node o){
  node ans;
  ans.t = o.t+1;
  ans.p = o.p + "B";
  for (int i = 0; i < 8; ++i)
	{
	  if((i+1)%4)
		ans.num[i+1] = o.num[i];
	  else
		ans.num[i-3] = o.num[i];
	}
  return ans;
}
node C(node o){
  node ans;
  ans.p = o.p + "C";
  ans.t = o.t+1;
  ans.num[0] = o.num[0];
  ans.num[3] = o.num[3];
  ans.num[4] = o.num[4];
  ans.num[7] = o.num[7];
  ans.num[1] = o.num[5];
  ans.num[2] = o.num[1];
  ans.num[5] = o.num[6];
  ans.num[6] = o.num[2];
  return ans;
}
bool cmp(node x,node y){
	for (int i = 0; i < 8; ++i)
	  {
		if (x.num[i] > y.num[i]) return true;
		else if(x.num[i] < y.num[i]) return false;
	  }
	return false;
}
struct cmpnode{
  bool operator() (const node& x, const node& y) const
  {
	return cmp(x,y);
  }
};
void print(node in){
  for (int i = 0; i < 8; ++i)
	{
	  cout << in.num[i];
	}
  cout << ' ';
  cout << in.p;
  cout << endl;
}
set<node,cmpnode> found;
void bfs(node root){
  queue<node> pool;
  pool.push(root);
  while(pool.size()){
	if(found.find(pool.front()) == found.end()){
	  if ((!cmp(ter,pool.front())) && (!cmp(pool.front(),ter))){
		fout << pool.front().t << endl;
		fout << pool.front().p <<endl;
		return;
	  }
	  //	  print(pool.front());
	  found.insert(pool.front());
	  pool.push(A(pool.front()));
	  pool.push(B(pool.front()));
	  pool.push(C(pool.front()));
	}
	pool.pop();
  }
}
int main(int arygc, char *argv[])
{
  origin.t = 0;
  origin.p = "";
  for (int i = 0; i < 4; ++i)
	{
	  origin.num[i] = i+1;
	  fin >> ter.num[i];
	}
  for (int i = 4; i < 8; ++i)
	{
	  origin.num[i] = 12 - i;
	  fin >> ter.num[ 11 - i ];
	}
  bfs(origin);
  return 0;
}

