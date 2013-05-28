#include <iostream>

#include <cstdio>
using namespace std;


int pr[50002];
int eat[50002] = {0};

int getpr(int a){
  if (pr[a]==a) return a;
  pr[a] = getpr(pr[a]);
  eat[a] = eat[pr[a]];
  return pr[a];
}
/*void union(int a,int b){
  a = getpr(a);
  b = getpr(b);
  if(a!=b)
    pr[b]=a;
    }*/

void same(int x,int y){
      int a = getpr(x),b=getpr(y);
      if(a!=b){
	if(eat[a]==b || eat[b]==a) ++ans;
	else {
	  pr[b] = a;
	  eat[b] = eat[a];
      }


int main(){
  int n,k;
  cin >> n >> k;
  for (int i=0;i<n;++i) pr[i+1] = i+1;
  int ans=0;
  for(int i=0;i<k;++i){
    int o,x,y;
    scanf("%d%d%d",&o,&x,&y);
    if(x>n || y>n) ++ans;
    else if(x==y && o==2) ++ans;
    else if(o==1) same(x,y);
    else if(o==2){
      int a=getpr(x),b=getpr(x);
      if(a==b) ++ans;
      else if (eat[b]==a) ++ans;
      else {
	int c = eat[a];
	if (c==0) eat[a] = b;
	else {

    }
  }
  cout << ans;
  return 0;
}
