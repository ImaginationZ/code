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
  if(length[i][x][y] < deep) return;
  length[i][x][y] = deep;
  bfs(x-1,y,i,deep+1);
  bfs(x+1,y,i,deep+1);
  bfs(x,y+1,i,deep+1);
  bfs(x,y-1,i,deep+1);
}

int main(int argc, char *argv[])
{
  string line;
  while(fin >> line)
    cout << line << endl;
  return 0;
}

