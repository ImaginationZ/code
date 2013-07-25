/*
ID: frequen1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

const int V=26;
const int G=20;

int need[V];
int feed[G][V];

int v,g;

int output[V];

int lowbit(int p){
  int ans=0;
  p &= -p;
  while(p){
    p/=2;
    ++ans;
  }
  return ans;
}

ofstream fout ("holstein.out");
ifstream fin ("holstein.in");

int main(int argc, char *argv[])
{
  int min = 1<<10;
  int pas;

  fin >> v;
  for (int i = 0; i < v; ++i)
    {
      fin >> need[i];
    }
  fin >> g;
  for (int i = 1; i <= g; ++i)
    {
      for (int j = 0; j < v; ++j)
        {
          fin >> feed[i][j];
        }
    }
  for (int p = 1; p < (1<<g); ++p)
    {
      for (int i = 0; i < v; ++i)
        {
          output[i] = 0;
        }
      int q = p;
      bool flag = 1;
      int t = 0;
      while(q){
        int k = lowbit(q);
        for (int i = 0; i < v; ++i)
          {
            output[i] += feed[k][i];
          }
        q -= q & -q;
        ++ t;
      }
      for (int i = 0; i < v; ++i)
        {
          if(output[i] < need[i]) flag = 0;
        }
      if(flag && t<min){
        min = t;
        pas = p;
      }
    }
  fout << min;
  while(min--){
    fout << ' ';
    fout << lowbit(pas);
    pas -= pas & -pas;
  } 
  fout << endl;
  return 0;
}
