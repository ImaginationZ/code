#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 1000005;

struct node{
	int lf;
	int rt;
	int pr;
	int n;
	node(){lf=rt=0;}
}tree[MAX];

void order(int root,int &n,int &max){
	int lf = tree[root].lf;
	int rt = tree[root].rt;
	if(lf){
		tree[lf].n = tree[root].n * 2;
		if (tree[lf].n > max) max = tree[lf].n ;
		order(lf,n,max);
	}
	if(rt){
		tree[rt].n = tree[root].n * 2 + 1;
		if (tree[rt].n > max) max = tree[rt].n ;
		order(rt,n,max);
	}
	++n;
}

int main() {
	int n;
	cin >> n;
	for (int i=1;i<n;++i){
		int pr;
		scanf("%d",&pr);
		tree[i].pr = pr;
		if(!tree[pr].lf) tree[pr].lf = i;
		else tree[pr].rt = i;
	}
	tree[0].n = 1;
	int nnode=0,max=1;
	order(0,nnode,max);
	if(max!=nnode) cout << "false";
	else cout << "true";

    return 0;
}
