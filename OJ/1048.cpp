#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 1024;

struct Tnode{
	int lf;
	int rt;
	int pr;
	Tnode(){lf=rt=pr=0;}
} tree[MAX];

int main() {
	int n;
	cin >> n;
	int a,b,c;
	while(3==scanf("%d%d%d",&a,&b,&c)){
		tree[a].lf = b;
		tree[a].rt = c;
		tree[b].pr = a;
		tree[c].pr = a;
	}
	int root = 1;
	while(tree[root].pr) root=tree[root].pr;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		c = q.front();
		printf("%d\n",c);
		if(tree[c].lf)q.push(tree[c].lf);
		if(tree[c].rt)q.push(tree[c].rt);
		q.pop();
	}

    return 0;
}
