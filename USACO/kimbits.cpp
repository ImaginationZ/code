/*
ID: frequen1
PROG: kimbits
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
ifstream fin ("kimbits.in");
ofstream fout ("kimbits.out");

long long  N,L,I;

long long num[32][32];

void ans(long long t, int l,int n){
  //  cerr << t << ' '<<l <<' '<<n <<endl;
  if(n==1){
	if(t==2) fout << '1';
	else fout << '0';
	fout << endl;
	return;
  }
  if(t > num[n-1][l] && l)
	{
	  fout << '1';	  
	  return ans(t- num[n-1][l], l-1, n-1);
	}
  else 
	{
	  fout << '0';
	  return ans(t,l,n-1);
	}
}

int main(int argc, char *argv[])
{
  fin >> N >> L >> I;
  num[1][0] = 1;
  for (int i = 1; i <= N; ++i)
	{
	  num[1][i] = 2;
	}
  for (int i = 2; i <= N; ++i)
  {
	num[i][0] = 1;
    for (int j = 1; j <= N; ++j)
	  {
		num[i][j] = num[i-1][j-1] + num[i-1][j]; 
	  }
  }
  ans(I,L,N);
  return 0;
}

