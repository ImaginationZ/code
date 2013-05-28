#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

struct node{
  node *lf;
  node *rt;
  int key;
  int fix;
  node(int k){key=k;fix=rand();lf = rt = NULL;}
}*root;

struct candy000{
  int pr;
  int n;
}candy[500005];


void lf(node *&root){
  node *tmp = root->rt;
  root->rt = tmp->lf;
  tmp->lf = root;
  root = tmp;
}

void rt(node *&root){
  node *tmp = root->lf;
  root->lf = tmp->rt;
  tmp->rt = root;
  root = tmp;
}
 
void insert(int key,node *&root){
  if(root == NULL){
    root = new node(key);
  }
  else if(key >= root->key){
    insert(key,root->lf);
   if(root->fix < root->lf->fix) rt(root);
  }
  else {
    insert(key,root->rt);
    if(root->fix < root->rt->fix) lf(root);
  }
}
  int getpr(int x){
    if(candy[x].pr == x) return x;
    else candy[x].pr = getpr(candy[x].pr);
    return candy[x].pr;
  }


void del(int key,node *&root){
  if(root==NULL) return;
  if(key > root->key){
    del(key,root->lf);
  }
  else if(key < root->key){
    del(key,root->rt);
  }
  else{
    if(root->lf == NULL){

      root = root->rt;
    }
    else if(root->rt == NULL){

      root = root->lf;
    }
    else if(root->lf->fix > root->rt->fix){
      rt(root);
      del(key,root->rt);
    }
    else{
      lf(root);
      del(key,root->lf);
    }
  }
}

void merge(int x,int y){
    int a = getpr(x);
    int b = getpr(y);
    if(a==0 || b==0) return;
    if(a==b) return;
    del(candy[a].n,root);
    del(candy[b].n,root);
    insert(candy[a].n+candy[b].n,root);
    candy[a].pr = b;
    candy[b].n += candy[a].n;
}

void eat(int x){
  int a = getpr(x);
  if(a==0)return;
  candy[a].pr = 0;
  del(candy[a].n,root);
}

int flag,t;

void ask(node *root){
  if(flag) return;
  if(root == NULL) return;
  ask(root->lf);
  t--;
  if(!t){
    printf("%d\n",root->key);
    flag = true;
  }
  ask(root->rt);
}



int main(){
  srand(time(NULL));
  int n,m;
  scanf("%d %d",&n,&m);
  root = NULL;
  for (int i=1;i<=n;++i){
    insert(1,root);
    candy[i].pr = i;
    candy[i].n = 1;
  }
  candy[0].n = 0;
  candy[0].pr = 0;

  while(m--){
    char op;
    scanf(" %c",&op);
    if(op == 'C'){
      int x,y;
      scanf("%d %d",&x,&y);
      merge(x,y);
    }
    else if(op == 'D'){
      int x;
      scanf("%d",&x);
      eat(x);
    }
    else if(op == 'Q'){
      int p;
      scanf("%d",&p);
      t = p;
      flag = false;
      ask(root);
        if(!flag) printf("0\n");
    }
  }
  return 0;
}
