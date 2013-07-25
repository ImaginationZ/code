/*
ID: frequen1
PROG: ttwo
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

string map[12];

ifstream fin ("ttwo.in");
ofstream fout ("ttwo.out");

int vx[4] = { -1, 0, 1, 0 };
int vy[4] = { 0, 1, 0, -1 };
struct crood{
  int x;
  int y;
  int v;
  void move(){
    if(map[x+vx[v]][y+vy[v]]=='*')
      v = (v+1) % 4;
    else {
    x += vx[v];
    y += vy[v];
    }
  }
}ob[2];

int main(int argc, char *argv[])
{
  map[0] = map[11] = "************";
  for (int i = 1; i <= 10; ++i)
    {
      string tmp;
      map[i] = "*";
      fin >> tmp;
      map[i].append(tmp);
      for (int j = 1; j < 11; ++j)
        {
          if (map[i][j] == 'F'){
            ob[0].x = i;
            ob[0].y = j;
            ob[0].v = 0;
          }
          if (map[i][j] == 'C'){
            ob[1].x = i;
            ob[1].y = j;
            ob[1].v = 0;
          }
        }
      map[i].append("*");
    }
  int i;
  for (i = 1; i < 160001; ++i)
    {
      ob[0].move();
      ob[1].move();
      //      cout << ob[0].x << ' '<< ob[0].y <<' '<< ob[1].x <<' '<<ob[1].y<<endl;
      if(ob[0].x == ob[1].x && ob[0].y == ob[1].y)
        break;
    }
  if (i == 160001 ) fout << 0 << endl;
  else fout << i << endl;
  return 0;
}

