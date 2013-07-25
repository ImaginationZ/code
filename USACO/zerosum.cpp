/*
ID: frequen1
PROG: zerosum
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

ifstream fin ("zerosum.in");
ofstream fout ("zerosum.out");

int n;

const int add = 10001;
const int leave = 10002;
const int blank = 10000;

int cal(int* a){
  int ans = 0;
  int now = 0;
  int op = add;
  for (int i = 0; i < n*2-1; ++i)
    {
      if(a[i] == blank){
        now*=10;
        now+=a[++i];
      }
      else if(a[i] == add){
        if(op == add) ans += now;
        else ans -= now;
        now = 0;
        op = add;
      }
      else if(a[i] == leave){
        if(op == add) ans += now;
        else ans -= now;
        now = 0;
        op = leave;
      }
      else now = a[i];
    }
  if(op == add) ans += now;
  else ans -= now;
  return ans;
}

void print(int *a){
  for (int i = 0; i < n*2-1; ++i)
    {
      if(a[i] == add)
        fout << '+';
      else if (a[i] == leave)
        fout << '-';
      else if (a[i] == blank)
        fout << ' ';
      else fout << a[i];
    }
  fout << endl;
}


int main(int argc, char *argv[])
{
  fin >> n;
  int a[20];
  for (int i = 1; i <= n; i++)
    {
      a[2*i-2] = i;
    }
  for (int i1 = blank; i1 <= leave; ++i1){
    for (int i2 = blank; i2 <= leave; ++i2){
      for (int i3 = blank; i3 <= leave; ++i3){
        for (int i4 = blank; i4 <= leave; ++i4){
          for (int i5 = blank; i5 <= leave; ++i5){
            for (int i6 = blank; i6 <= leave; ++i6){
              for (int i7 = blank; i7 <= leave; ++i7){
                for (int i8 = blank; i8 <= leave; ++i8){
                  a[1] = i1;
                  a[3] = i2;
                  a[5] = i3;
                  a[7] = i4;
                  a[9] = i5;
                  a[11] = i6;
                  a[13] = i7;
                  a[15] = i8;
                  if(cal(a)==0)
                    print (a);
                  if(n < 9) break;
                }
                if(n < 8) break;
              }
              if(n < 7) break;
            }
            if(n < 6) break;
          }
          if(n < 5) break;
        }
        if(n < 4) break;
      }
      if(n < 3) break;
    }
    if(n < 2) break;
  }

                              
  return 0;
}

