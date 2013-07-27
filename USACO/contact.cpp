/*
ID: frequen1
PROG: contact
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
ifstream fin ("contact.in");
ofstream fout ("contact.out");

int f[13][10000] = {0};

string s = "";

struct node{
  int length;
  int bit;
  int times;
}res[100000];

bool cmp(node a,node b){
  if (a.times > b.times) return true;
  if (a.times == b.times && a.length < b.length) return true;
  if (a.times == b.times && a.length == b.length && a.bit < b.bit) return true;
  return false;
}

void count(int length){
  int tmp = length - 1;
  int sum = 0;
  int p = 0;
  while(tmp--)
	{
	  sum <<= 1;
	  sum += s[p] - '0';	 
	  p++;
	  if( p> s.size()) return;
	}
  while(true)
	{
	  sum &= (1<<(length-1)) - 1;
	  sum <<= 1;
	  sum |= s[p] - '0';
	  f[length][sum]++;
	  ++p;
	  cout << p << endl;
	  if(p > s.size()) return;
	} 
}

void print(int length, int bit){
  int tmp[50] = {0};
  int idx = 0;
  while(bit){
	tmp[idx++] = bit%2;
	bit/=2;
  }
for (int i = length-1; i >= 0; --i)
  {
    fout << tmp[i];
  }
}

int main(int argc, char *argv[])
{
  string tmp = "";
  int a,b,n;
  fin >> a >> b >> n;
  while(fin >> tmp){
	s.append(tmp);
  }
  b = (b > s.size())? s.size() : b;
  for (int i = a; i <= b ; ++i)
	{
	  count(i);
	}
  int idx = 0;
  for (int i = a; i <= b; ++i)
	{
	  for (int j = 0; j < (1<<i); ++j)
		{
		  res[idx].times = f[i][j];
		  res[idx].length = i;
		  res[idx++].bit = j;
		}
	}
  sort(res,res+idx,cmp);
  int p = 0;
  do
	{
	  int nth = res[p].times;
	  if(!nth) break;
	  fout << nth << endl;
	  print(res[p].length,res[p].bit);
	  while ( res[++p].times == nth){
		fout <<' ';
		print(res[p].length,res[p].bit);
	  }
	  n--;
	  fout << endl;
	} while (n);
	
  return 0;
}

