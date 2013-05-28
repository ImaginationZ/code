#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node{
	int key;
	int dis;
	node *lf;
	node *rt;
	node(int charm){key = charm;lf = rt = NULL;dis=0;}
};

node *root[300005];

node *merge(node*& a,node*& b){
	if (a==NULL) return b;
	if (b==NULL) return a;
	if (b->key<a->key) swap(a,b);
	a->rt = merge(a->rt,b);
	if(a->rt!=NULL)
		if(a->lf==NULL || a->rt->dis > a->lf->dis)
			swap(a->rt,a->lf);
	if (a->rt==NULL) a->dis = 0;
	else a->dis = a->rt->dis + 1;
	return a;
}

void insert(int x,node *&a){
	node *b = new node(x);
	a = merge(a,b);
	delete b;
}

void pop(node *&a){
	if (a==NULL){
		printf("-1\n");
		return;
	}
	printf("%d\n",a->key);
	a = merge(a->lf,a->rt);
}

int main() {
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;++i){
		int charm;
		scanf ("%d",&charm);
		root[i] = new node(charm);
	}
	for (int i=0;i<m;++i){
		int op,a,b;
		scanf("%d",&op);
		switch(op){
			case 0: scanf("%d %d",&a,&b); root[a]=merge(root[a],root[b]);break;
			case 1: scanf("%d",&a); pop(root[a]);break;
			case 2: scanf("%d %d",&a,&b);insert(b,root[a]);break;
		}
	}


    return 0;
}
