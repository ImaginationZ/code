/*
ID: frequen1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int map[55][55];
bool visited[55][55] = {0};
int mark[55][55];

int N,M;

using namespace std;

ofstream fout ("castle.out");
ifstream fin ("castle.in");

int idx;
int num[2501]={0};

inline bool valid(int i,int j){
  return (i>=0) && (j>=0) && (i<N) && (j<M);
}

void bfs(int i,int j,int m){
  if(!valid(i,j)) return;
  if(visited[i][j]) return;
  visited[i][j] = 1;
  mark[i][j] = m;
  num[m]++;
  int p = map[i][j];
  if((p & 1)==0)
    bfs(i,j-1,m);
  if((p & 2)==0)
    bfs(i-1,j,m);
  if((p & 4)==0)
    bfs(i,j+1,m);
  if((p & 8)==0)
    bfs(i+1,j,m);
}

int removeN(int i,int j){
  if(!valid(i-1,j)) return num[mark[i][j]];
  if(mark[i-1][j]==mark[i][j]) return num[mark[i][j]];
  return num[mark[i][j]] + num[mark[i-1][j]];
}

int removeE(int i,int j){
  if(!valid(i,j+1)) return num[mark[i][j]];
  if(mark[i][j+1]==mark[i][j]) return num[mark[i][j]];
  return num[mark[i][j]] + num[mark[i][j+1]];
}

int main(int argc, char *argv[])
{
  fin >> M >> N;
  idx = 0;
  for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < M; ++j)
        {
          fin >> map[i][j];
        }
    }
  for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < M; ++j)
        {
          if(!visited[i][j]){
            bfs(i,j,idx);
            idx++;
          }
        }
    }
  int max = 0;
  for (int i = 0; i < idx; ++i)
    {
      if(num[i] > max)
        max = num[i];
    }
  fout << idx << endl;
  fout << max << endl;

  max = 0;
  int x,y;
  char choose;
  for (int j = 0; j < M; ++j)
    {
      for (int i = N-1; i >= 0; --i)
        {
          int n = removeN(i,j);
          int e = removeE(i,j);
          //          cerr << n <<' '<< i+1<< ' '<< j+1 << 'N'<< endl;
          //          cerr << e <<' '<< i+1 <<' '<< j+1 << 'E'<< endl;
          if(n > max){
            max = n;
            x = i;
            y = j;
            choose = 'N';
          }
          if(e > max){
            max = e;
            x =i;
            y = j;
            choose = 'E';
          }
        }
    }
  fout << max << endl;
  fout << x+1 << ' ' << y+1 << ' ' << choose << endl;
  return 0;
}
