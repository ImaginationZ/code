#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std; 


class heap{
 public:
  int *line;
  int capasity;
  int size;
  heap(){size=0;capasity = 4;line = new int[4];}
  void doublespace(){
    capasity *= 2;
    int *tmp = new int[capasity];
    for(int i = 1;i<=size;++i)
      tmp[i] = line[i];
    delete[] line;
    line = tmp;
  }
  void insert(int key){
    if (size == capasity - 1) doublespace();
    ++size;
    line[size] = key;
    int p = size;
    while(p>1&&line[p]>line[p/2]){
      swap(line[p],line[p/2]);
      p /= 2;
    }
  }
  void change(){
    line[1] /= 2;
    int p = 1;
    while(p<=size&&!(line[p] >= line[2*p] && line[p] >= line[2*p+1])){
      int t = (line[p*2] > line[2*p+1])? 2*p:2*p+1;
      swap(line[p],line[t]);
      p = t;
    }
  }

  int m(){return line[1];}
  void clear(){delete[] line;}
};

int pr[100005];
heap h[100005];

int getpr(int x){
  if(pr[x] == x) return x;
  else pr[x] = getpr(pr[x]);
  return pr[x];
}

void merge(int x,int y){
  int a = getpr(x);
  int b = getpr(y);
  if(a==b){
    printf("-1\n");
    return;
  }
  if(h[a].size < h[b].size){
    merge(b,a);
    return;
  }
  (h[b].line)[1] /= 2;
  h[a].change();
  for(int i=1;i<=h[b].size;++i)
    h[a].insert((h[b].line)[i]);
  h[b].clear();
  pr[b] = a;
  printf("%d\n",h[a].line[1]);
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;++i){
    int x;
    scanf("%d",&x);
    h[i].insert(x);
    pr[i] = i;
  }
  int m;
  scanf("%d",&m);
  while(m--){
    int a,b;
    scanf("%d%d",&a,&b);
    merge(a,b);
  }
  return 0;
}
