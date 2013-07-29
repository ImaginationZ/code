/*
ID: frequen1
PROG: ratios
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
ifstream fin ("ratios.in");
ofstream fout ("ratios.out");


long long feed[4][4];

long long gcd(long long x,long long y){
  if(x<0) x=-x;
  if(y<0) y=-y;
  if(x>y) swap(x,y);
  if(y==0) return oo;
  if(x==0) return y;
  if(y == oo) return x;
  if(x==y) return x;
  return gcd(y-x,x);
}

long long s(long long** feed){
	return feed[1][1]*feed[2][2]*feed[3][3] + feed[1][2]*feed[2][3]*feed[3][1] + feed[1][3]*feed[2][1]*feed[3][2] - feed[1][1]*feed[2][3]*feed[3][2] - feed[3][3]*feed[1][2]*feed[2][1] - feed[3][1]*feed[2][2]*feed[1][3];
}

int main(int argc, char *argv[])
{
  for (int i = 0; i < 4; ++i)
	{
	  fin >> feed[i][1] >> feed[i][2] >> feed[i][3];
	}
  long long **left,**m1,**m2,**m3;
  left = new long long*[4];
  m1 = new long long*[4];
  m2 = new long long*[4];
  m3 = new long long*[4];
  m2[1] = m3[1] = left[1] = feed[1];
  m1[2] = m3[2] = left[2] = feed[2];
  m1[3] = m2[3] = left[3] = feed[3];
  m1[1] = m2[2] = m3[3] = feed[0];
  long long p = s(left);
  for (long long i = 0; i < 4; ++i)
	{
	  feed[0][i] *= (p>0)? p:-p;
	}
  long long f1 = s(m1)/p;
  long long f2 = s(m2)/p;
  long long f3 = s(m3)/p;
  int m = gcd(gcd(f1,gcd(f2,f3)),p);
  f1/=m;
  f2/=m;
  f3/=m;
  p/=m;
  if(f1>=0 && f2>=0 && f3>=0 && p && f1<100 && f2<100 && f3<100 && p<100)
	fout << f1 <<' '<<f2<<' '<<f3<<' '<<((p>0)?p:-p)<<endl;
  else fout << "NONE"<<endl;
  return 0;
}

