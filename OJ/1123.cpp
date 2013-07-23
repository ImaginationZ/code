#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N=50005, X=100005, K=12, mod=100007;
int f[N][K][2]={0};
int s[2][K][X] = {0};
int s0[K] = {0},s1[K] = {0};
struct coord{
  int x;
  int y;
}p[N];
int n,k;

int lowbit(int p){
  return p & (-p);
}

int sum(int* s, int end){
  int sum=0;
  while(end > 0){
    sum += s[end];
    end -= lowbit(end);
  }
  return sum;
}

void add(int* s, int pos, int key){
  while( pos < X){
    s[pos] += key;
    pos += lowbit(pos);
  }
}

bool cmp(coord a, coord b){
  return a.x > b.x;
}

int main(int argc, char *argv[])
{
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    {
      cin >> p[i].x >> p[i].y;
    }
  sort(p+1, p+1+n, cmp);
  for (int i = 1; i <= n; ++i)
    {
      f[i][0][0] = 1;
      f[i][0][1] = 1;
      add(s[0][0], p[i].y, 1);
      add(s[0][1], p[i].y, 1);
      s0[0]++;
      s1[0]++;
      for (int j = 1; j <= K; ++j)
        {
          f[i][j][0] = (sum(s[1][j-1],p[i].y-1) + sum(s[0][j],p[i].y-1)) % mod;
          f[i][j][1] = (s0[j-1] + s1[j] - sum(s[0][j-1],p[i].y) - sum(s[1][j],p[i].y)) % mod;
          add(s[0][j], p[i].y, f[i][j][0]);
          add(s[1][j], p[i].y, f[i][j][1]);
          s0[j] += f[i][j][0];
          s1[j] += f[i][j][1];
        }
    }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    {
      ans += f[i][k][0] + f[i][k][1];
      ans %= mod;
    }
  cout << ans <<endl;
  return 0;
}
