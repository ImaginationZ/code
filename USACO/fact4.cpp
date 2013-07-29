/*
ID: frequen1
PROG: fact4
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
ifstream fin ("fact4.in");
ofstream fout ("fact4.out");

int main(int argc, char *argv[])
{
  long long n;
  fin >> n;
  long long p = 1;
  for (long long i = 1; i <= n; ++i)
	{
	  p *= i;
	  while( p%10 == 0)
		p/= 10;
	  p %= 100000000;
	}
  fout << p%10 << endl;
  return 0;
}

