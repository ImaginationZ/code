#include <iostream>
using namespace std;

int find(int k,int h){
  if(h==1) return 1;
  else {
    int ans = 0;
    for(int i=0;i<k;++i)
      ans += find(k-i,h-1);
    return ans;
  }
}
int main(){
  int k,h;
  cin >> k >> h;
  cout << find (k,h);
  return 0;
}
