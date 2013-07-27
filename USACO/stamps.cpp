/*
ID: frequen1
PROG: stamps
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
#include <vector>
using namespace std;
const long oo = (1LL<<31)-1;
ifstream fin ("stamps.in");
ofstream fout ("stamps.out");


int k,n;
int stamp[70];

bool enable[2000009] = {0};
bool updated[2000009] = {0};

int main(int argc, char *argv[])
{
  fin >> k >> n;
  for (int i = 0; i < n; ++i)
	{
	  fin >> stamp[i];
	}
  sort(stamp,stamp+n);
  for (int i = 0; i < n; ++i)
	{
	  enable[stamp[i]] = 1;
	}
  int last = 0;
  for (int i = 1; i < k; ++i)
	{
	  for (int j = i * stamp[n-1] + 5; j>last ; --j)
		{
		  if( enable[j] && !updated[j])
			{
			  updated[j] = 1;
			  for (int s = 0; s < n; ++s)
				{
				  enable[j+stamp[s]] = 1;
				}
			}
		}
	}
  for (int i = 1; i <= k * stamp[n-1]; ++i)
	{
	  //	  if(enable[k][i]) cout << i <<' ';
	  if(enable[i] && !enable[i+1] ){
		fout << i << endl;
		break;
	  }
	}
  return 0;
}
