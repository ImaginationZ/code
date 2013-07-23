/*
ID: frequen1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

int n;
struct frac{
  int x;
  int y;
  void reduce(){
    for (int i = x; i > 0; --i)
      {
        if( (x%i==0) && (y%i==0) ){
          x /= i;
          y /= i;
          break;
        }
      }
  }
}pool[40000];

bool cmp(frac a,frac b){
  return a.x/(double)a.y < b.x/(double)b.y;
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    fin >> n;
    int idx = 0;
    for (int i = 1; i <= n; ++i)
      {
        for (int j = 1; j <= i; ++j)
          {
            pool[idx].y = i;
            pool[idx++].x = j;
          }
      }
    sort(pool,pool+idx,cmp);
    frac last;
    last.x = 0;
    last.y = 1;
    fout << last.x << '/' << last.y << endl;
    for (int i = 0; i < idx; ++i)
      {
        pool[i].reduce();
        if(pool[i].x != last.x || pool[i].y != last.y){
          last = pool[i];
          fout << last.x << '/' << last.y << endl;
        }
      }
    return 0;
}
