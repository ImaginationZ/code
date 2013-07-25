/*
ID: frequen1
PROG: preface
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

ifstream fin ("preface.in");
ofstream fout ("preface.out");

struct node{
  int n;
  char name;
}digits[7];

void count(int num){
  int d[4] = {0};
  int p = 0;
  while(num){
    d[p++] = num%10;
    num /= 10;
  }
  digits[6].n += d[3];
  for (int i = 0; i < 3; ++i)
    {
      if(d[i] < 4) digits[2*i].n += d[i];
      else if( d[i] == 4){
        digits[2*i].n++;
        digits[2*i+1].n++;
      }
      else if ( d[i] == 5) digits[2*i+1].n++;
      else if ( d[i] < 9){
        digits[2*i].n += d[i]-5;
        digits[2*i+1].n ++;
      }
      else {
        digits[2*i].n++;
        digits[2*i+2].n++;
      }
    }
}

bool cmp(node a,node b){
  return a.n > b.n;
}

int main(int argc, char *argv[])
{
  int N;
  fin >> N;
  digits[0].name = 'I';
  digits[1].name = 'V';
  digits[2].name = 'X';
  digits[3].name = 'L';
  digits[4].name = 'C';
  digits[5].name = 'D';
  digits[6].name = 'M';
  for (int i = 1; i <= N; ++i)
    {
      count(i);
    }
  for (int i = 0; i < 7; ++i)
    {
      if(digits[i].n)
        fout << digits[i].name << ' ' << digits[i].n << endl;
    }
  return 0;
}

