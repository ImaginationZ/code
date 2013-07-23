/*
ID: frequen1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int  MAX = 100000;
int out[MAX];
int idx;


void test(int p){
  for (int i = 2; i <= sqrt(p); ++i)
    {
      if(p % i == 0)
        return;
    }
  out[idx++] = p;
}

int main() {
  int a,b;
  idx=0;
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    fin >> a >> b;
    for (int i = 0; i < 10000; ++i)
      {
        int p = i;
        int q = 0;
        int t = 0;
        while(p){
          ++t;
          q*=10;
          q+=p%10;
          p/=10;
        }
        p=i;
        int tmp = t;
        while(t--)
          p*=10;
        q+=p;
        test(q);
        q-=p;
        p=i/10;
        while(tmp--)
          p*=10;
        q+=p;
        test(q);
      }
        sort(out,out+idx);
    int last=0;
    for (int i = 0; i < idx; ++i)
      {
        if(out[i]>b) break;
        if(out[i]>=a && out[i]!=last) fout << out[i] << endl;
        last = out[i];
      }

   return 0;
}
