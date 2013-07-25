/*
ID: frequen1
PROG: cowtour
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
#include <list>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

const int infinite = 1<<30;
const int N = 155;
struct crood{
  int x;
  int y;
}point[N];
int n;

double getdis(int i, int j){
  crood a = point[i];
  crood b = point[j];
  return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

ifstream fin ("cowtour.in");
ofstream fout ("cowtour.out");

double weight[N][N];
double dis[N][N];
double longest[N]={0};
double m=infinite;
double mm = 0;

int main(int argc, char *argv[])
{
  fin >> n;
  for (int i = 0; i < n; ++i)
	{
	  fin >> point[i].x >> point[i].y;
	}
  string tmp;
  getline(fin,tmp);
  for (int i = 0; i < n; ++i)
	{
	  string line;
	  getline(fin,line);
	  for (int j = 0; j < n; ++j)
		{
		  if (line[j] == '1'){
			dis[i][j] = dis[j][i] = weight[i][j] = weight[j][i] = getdis(i,j);
		  }
		  else 	dis[i][j] = dis[j][i] = weight[i][j] = weight[j][i] = infinite;
		}
	}
  for (int k = 0; k < n; ++k)
	{
	  for (int i = 0; i < n; ++i)
		{
		  for (int j = 0; j < n; ++j)
			{
			  if( dis[i][k] + dis[k][j] < dis[i][j])
				dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
			}
		}
	}
  for (int i = 0; i < n; ++i)
	{
	  for (int j = i+1; j < n; ++j)
		if(dis[i][j] < infinite)
		  {
			if(dis[i][j] > longest[i]) longest[i] = dis[i][j];
			if(dis[i][j] > longest[j]) longest[j] = dis[i][j];
			if(dis[i][j] > mm) mm = dis[i][j];
		  }
	}
  for (int i = 0; i < n; ++i)
	{
	  for (int j = i+1; j < n; ++j)
		{
		  if(dis[i][j] >= infinite-1){
			double path = getdis(i,j) + longest[i] + longest[j];
			if (path < m)
			  m = path;
		  }
		}
	}
  fout << fixed << setprecision(6) << max(m,mm) << endl;
  return 0;
}

