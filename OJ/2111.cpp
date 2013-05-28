#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

typedef struct Node{
  int key;
  int fix;
  Node *lf;
  Node *rt;
  Node(int k){fix = rand();key = k;lf = rt = NULL;}
}node,*treap;

treap root;

void rot_lf(treap &root){
  node *tmp = root->rt;
  root->rt = tmp->lf;
  tmp->lf = root;
  root = tmp;
}

void rot_rt(treap &root){
  node *tmp = root->lf;
  root->lf = tmp->rt;
  tmp->rt = root;
  root = tmp;
}

void insert(int key,treap &root){
  if(root == NULL){
    root = new node(key);
  }
  else if(key < root->key){
    insert(key,root->lf);
    if(root->lf->fix < root->fix)
      rot_rt(root);
  }
  else {
    insert(key,root->rt);
    if(root->rt->fix < root->fix)
      rot_lf(root);
  }
}

void del(int key,treap &root){
  if(root == NULL) return;
  if(root->key == key){
    if(root->lf == NULL && root->rt == NULL){
      delete root;
      root = NULL;
    }
    else if(root->lf == NULL){
      treap tmp = root;
      root = root->rt;
      delete tmp;
    }
    else if (root->rt == NULL){
      treap tmp = root;
      root = root->lf;
      delete tmp;
    }
    else if(root->lf->fix < root->rt->fix){
      rot_rt(root);
      del(key,root->rt);
    }
    else {
      rot_lf(root);
      del(key,root->lf);
    }
  }
  else if(key < root->key)
    del(key,root->lf);
  else del(key,root->rt);
}

bool find(int key,treap root,int &max,int &min){
  if(root==NULL)
    return false;
  else if(key < root->key){
    if(root->key < max) max = root->key;
    return find(key,root->lf,max,min);
  }
  else{
    if(root->key > min) min = root->key;
    return find(key,root->rt,max,min);
  }
}

int ask(int key){
  int ans,min=-1,max=100000001;
  find(key, root, max, min);
  if(min==-1) ans = max - key;
  else if(max==100000001) ans = key - min;
  else {
    min = key - min;
    max = max - key;
    ans = (min<max)? min:max;
  }
  printf("%d\n",ans);
}

int main(){
  int m;
  int op,x;
  cin >> m;
  while(m--){
    scanf("%d%d",&op,&x);
    switch(op){
    case 0:ask(x);break;
    case 1:insert(x, root);break;
    case 2:del(x, root);break;
    }
  }
  return 0;
}
