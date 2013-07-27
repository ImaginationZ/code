/*
ID: frequen1
PROG: humble
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

ifstream fin ("humble.in");
ofstream fout ("humble.out");

const long N = 100005;
const long K = 105;
long n,k;

vector<int> res;
long p[K];
long pos[K];

int main(int argc, char *argv[])
{
  fin >> k >> n;
  for (long i = 0; i < k; ++i)
	{
	  fin >> p[i];
	  pos[i] = 0;
	}
  sort(p,p+k);
  res.push_back(1);
  while(true){
	long long min = (1LL<<31) -1;
	for (long i = 0; i < k; ++i)
	  {
		if ( min > p[i] * res[pos[i]] )
		  {
			min =  p[i] * res[pos[i]];
		  }
	  }
	for (long i = 0; i < k; ++i)
	  {
		while ( min == p[i] * res[pos[i]] )
		  pos[i]++;
	  }
	res.push_back(min);
	if(res.size() > n) break;
  }
  fout << res[n] << endl;
  return 0;
}

