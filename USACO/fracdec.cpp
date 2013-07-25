/*
ID: frequen1
PROG: fracdec
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

ifstream fin ("fracdec.in");
ofstream fout ("fracdec.out");

long long gcd(long long x, long long y){
  if(x==y) return x;
  if(x<y) swap(x,y); 
  return gcd(x-y,y);
}

int countime = 0;
void count(){
  ++ countime;
  if (countime <= 76) return;
  fout << endl;
  countime = 1;
}

int main()
{

  long long a,b;
  fin >> a >> b;
  fout << a/b << ".";
  int i = a/b;
  if(i==0) countime++;
  while(i){
	countime++;
	i/=10;
  }
  countime++;
  a %= b;
  if( a == 0 ){
	fout << "0"<<endl;
	return 0;
  }
  long long g = gcd(a,b);
  a /= g;
  b /= g;
  long long ten,two,five;
  ten = two = five = 0;
  while(b%10 == 0){
	b /= 10;
	++ ten;
  }
  while(b%2 == 0){
	b/= 2;
	++ two;
  }
  while(b%5 == 0){
	b/= 5;
	++five;
  }
  a *= pow(2,five) * pow(5,two);
  b *= pow(10,ten+two+five);
  while ( b%10 == 0){
	b /= 10;
	count();
	fout << a/b;
	a %= b;
  }
  if(b==1){
	fout << endl;
	return 0;
  }
  int n = 1;
  int s = 0;
  for (; ; ++n)
	{
	  s*=10;
	  s+=9;
	  s%=b;
	  if(s==0) break;
	}
  count();
  fout << "(";
  while(n--){
	a *= 10;
	count();
	fout << a/b;
	a %= b;
  }
  count();
  fout << ")" << endl;
  return 0;
}

