#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 40000;

queue<int> af;

struct Tnode{
	int lf;
	int rt;
	int n;
	Tnode(){lf=rt=-1;}
}tree[MAX];

void aforder(int root){
	if(tree[root].lf!=-1){
		tree[tree[root].lf].n = 2*tree[root].n;
		aforder(tree[root].lf);
	}
	if(tree[root].rt!=-1){
		tree[tree[root].rt].n = 2*tree[root].n+1;
		aforder(tree[root].rt);
	}
	af.push(root);
}

int main() {
	int n;
	cin >> n;
	for (int i=1;i<=n;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		tree[x].lf = y;
		tree[x].rt = z;
	}
	tree[1].n = 1;
	aforder(1);
	for (int i=1;i<=n;++i)
		printf("%d ",tree[i].n);
	cout << endl;
	while(!af.empty()){
		printf("%d ",af.front());
		af.pop();
	}



    return 0;
}
