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
	int key;
	node(){lf=rt=0;}
}tree[MAX];

/*class Tqueue{
	struct Tnode{
		int key;
		Tnode *next;
		Tnode(int x){key=x;next = NULL;}
	}*head;
public:
	Tqueue(){head=new Tnode(0);}
	void insert(int x){
		Tnode *p=head;
		while(p->next!=NULL) p=p->next;
		p->next=new Tnode(x);
	}
	int pop(){
		if(head->next==NULL) return -1;
		int t = head->next->key;
		head->next = head->next->next;
		return t;
	}
};*/

int main() {
	int n;
	cin >> n;
	for (int i=1;i<n;++i){
		int pr;
		scanf("%d",&pr);
		tree[i].pr = pr;
		if(!tree[pr].lf) tree[pr].lf = i;
		else tree[pr].rt = i;
		tree[i].key = i;
	}
	queue<int> q;
	q.push(0);
	int c;
	while(!q.empty()){
		c = q.front();
		q.pop();
		printf("%d ",c);
		if(tree[c].lf) q.push(tree[c].lf);
		if(tree[c].rt) q.push(tree[c].rt);
	}

    return 0;
}
