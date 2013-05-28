#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;


const int  MAX = 100005;

struct Tnode{
	int x;
	int order;
	int nodesum;
	bool red;
	int redsum;
	Tnode *lfgrand;
	Tnode *pr;
	Tnode *lf;
	Tnode *rt;
	Tnode(){red=redsum=nodesum=0;}
}node[MAX];

Tnode *order[MAX];

int seq = 0;

int inorder(Tnode *root,Tnode *null){
	int a=0,b=0;
	if(root->lf!=null) {
		a = inorder(root->lf,null);
		root->lfgrand = root->lf->lfgrand;
	}
	else root->lfgrand = root;
	order[seq] = root;
	root->order = seq;
	++seq;
	if(root->rt!=null)  b = inorder(root->rt,null);
	root->nodesum = a+b+1;
	return a+b+1;
}

int inordercountred(Tnode *root,Tnode *null){
	int a=0,b=0,c=0;
	if(root->lf!=null)	a = inordercountred(root->lf,null);
	if(root->red) c=1;
	if(root->rt!=null)  b = inordercountred(root->rt,null);
	root->redsum = a+b+c;
	return a+b+c;
}

int main() {
	int n,p,q;
	scanf("%d %d %d",&n,&p,&q);
	for (int i=0;i<=n;++i){
		(node+i)->x = i;
		(node+i)->pr = node;
		(node+i)->lf = node;
		(node+i)->rt = node;
	}
	for (int i=0;i<n;++i){
		int x,lx,rx;
		scanf("%d %d %d",&x,&lx,&rx);
		(node+x)->lf = node+lx;
		(node+x)->rt = node+rx;
		(node+lx)->pr = node+x;
		(node+rx)->pr = node+x;
	}
	Tnode *root = node+1;
	while(root->pr!=node)
		root = root -> pr;
	inorder(root,node);
	for (int i=0;i<p;++i){
		int t,x;
		scanf("%d %d",&t,&x);
		int pstart = (node+t)->lfgrand->order;
		int y = (node+t)->nodesum;
		Tnode *pred = order[pstart+x%y];
		if(!pred->red){
			pred->red=1;
		/*	while (pred!=node){
				++pred->redsum;
				pred = pred->pr;
			}*/
		}
	}
	inordercountred(root,node);
	for (int i=0;i<q;++i){
		int w;
		scanf("%d",&w);
		printf("%d\n",(node+w)->redsum);
	}

    return 0;
}
