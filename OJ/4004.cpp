#include <iostream>

using namespace std;

int num[64][64];

int main(){
  num[1][1]=num[1][2]=num[1][3]=1;
  int n;
  int ans=0;
  cin >> n;
  for (int i=2;i<=n;++i){
    num[i][1] = num[i][i+2] = 1;
    for (int j=2;j<=n+1;++j)
      num[i][j] = num[i-1][j-1] + num[i-1][j];
  }
  for (int i=1;i<n+3;++i)
    if(num[n][i]>ans) ans=num[n][i];
  cout << ans;
  cin >> ans;
  return 0;
}
