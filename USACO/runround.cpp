/*
ID: frequen1
PROG: runround
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


ifstream fin ("runround.in");
ofstream fout ("runround.out");

long M;
long pool[100000];
long idx=0;

bool contain(int p,int d){
  while(p){
    if(d==p%10) return true;
    p/=10;
  }
  return false;
}

bool test(int num){
  long t = 0;
  long p[10];
  bool visited[10]={0};
  long v = 0;
  while(num){
    p[t++] = num%10;
    num /= 10;
  }
  long pos=t-1;
  while(!visited[pos]){
    ++v;
    visited[pos] = 1;
    pos -= p[pos];
    while(pos < 0)
      pos = t + pos;
  }
  if(pos != t-1) return false;
  if(v==t) return true;
  return false;
}

long find(long m){
  int min = 1<<30;
  int ans;
  for (int i = 0; i < idx; ++i)
    {
      if(  pool[i] - m > 0 && pool[i] - m < min)
        {
          min = pool[i] - m;
          ans = pool[i];
        }
    }
  return ans;
}

int main(int argc, char *argv[])
{
  fin >> M;
  stack<long> s;
  for (long i = 1; i <= 9; ++i)
    {
      s.push(i);
    }
  while(!s.empty()){
    long now = s.top();
    s.pop();
    if(test(now)){
      pool[idx++] = now;
      //      cerr << now << endl;
    }
    for (long d = 1; d < 10; ++d)
      {
        if(!contain(now,d)){
          long tmp = now;
          int b = d;
          while(tmp){
            b*=10;
            tmp/=10;
          }
          s.push(b+now);
        }
      }
  }
  sort(pool,pool+idx);

  fout << find(M) << endl;
  return 0;
}

