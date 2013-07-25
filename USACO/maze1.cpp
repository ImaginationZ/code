/*
ID: frequen1
PROG: maze1
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

using namespace std;

const int MAX = 1<<30;
const int W = 40;
const int H = 105;

char map[2*H+1][2*W+1];

int w,h;

int x0[2];
int yy[2];
int idx = 0;

ifstream fin ("maze1.in");
ofstream fout ("maze1.out");

int length[2][2*H+1][2*W+1];

inline bool valid(int x, int y){
  return (x >= 1 && x <= 2*h +1 && y >= 1 && y<= 2*w +1 && map[x][y] == ' ');
}

void bfs(int x, int y, int i, int deep){
  if(!valid(x,y)) return;
  if(length[i][x][y] <= deep) return;
  length[i][x][y] = deep;
  bfs(x-1,y,i,deep+1);
  bfs(x+1,y,i,deep+1);
  bfs(x,y+1,i,deep+1);
  bfs(x,y-1,i,deep+1);
}

int main(int argc, char *argv[])
{
  fin >> w >> h;
  fin.get();
  for (int i = 1; i <= h * 2 + 1; ++i)
    {
      string line="";
      getline(fin,line,'\n');
      for (int j = 1; j <= w * 2 + 1; ++j)
        {
          map[i][j] = line[j-1];
          length[1][i][j] = length[0][i][j] = 1<< 30;
          if(map[i][j] == ' ')
            if(i==1 || j==1 || i==2*h+1 || j==2*w+1)
              {
                x0[idx] = i;
                yy[idx++] = j;
              }
        }
    }
  bfs(x0[0],yy[0],0,0);
  bfs(x0[1],yy[1],1,0);
  int max = 0;
    for (int i = 1; i <= h * 2 + 1; ++i)
    {
      for (int j = 1; j <= w * 2 + 1; ++j)
        {
          if (length[1][i][j] != 1<< 30)
            {
              int m = min(length[0][i][j],length[1][i][j]);
              m = (m+1)/2;
              if(m > max)
                max = m;
            }
        }
    }
    fout << max << endl;
  return 0;
}

