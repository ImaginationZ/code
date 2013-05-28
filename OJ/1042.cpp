#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 12346;

struct Tnode{
	int num;
	Tnode *former;
	Tnode *lfson;
	Tnode *rtbro;
} node[MAX];

class Tqueue{
	struct Lnode{
		Tnode *what;
		Lnode *next;
	}*head;
public:
	Tqueue(){
		head=new Lnode;
		head->next=NULL;
	}

	void insert(Tnode *what){
		Lnode *p = head;
		while (p->next!=NULL)
			p = p->next;
		p = p->next = new Lnode;
		p->what = what;
		p->next = NULL;
	}

	Tnode *pop(){
		if (head->next==NULL) return NULL;
		Lnode *tmp = head->next;
		Tnode *ans = tmp->what;
		head->next = tmp->next;
		delete tmp;
		return ans;
	}
};

const void preorder(Tnode *root,Tnode *null){
	cout << root->num << ' ';
	if (root->lfson!=null) preorder(root->lfson,null);
	if (root->rtbro!=null) preorder(root->rtbro,null);
}

const void aftorder(Tnode *root,Tnode *null){
	if (root->lfson!=null) aftorder(root->lfson,null);
	cout << root->num << ' ';
	if (root->rtbro!=null) aftorder(root->rtbro,null);
}

const void hierachy(Tnode *root,Tnode *null){
	Tqueue queue;
	queue.insert(root);
	Tnode *leftnode = NULL;
	while((leftnode = queue.pop()) != NULL){
		while (leftnode!=null){
			cout << leftnode->num <<' ';
			if (leftnode->lfson!=null) queue.insert(leftnode->lfson);
			leftnode = leftnode->rtbro;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i=0;i<MAX;++i){
		node[i].num = i;
		node[i].former = node[i].lfson = node[i].rtbro = node;
	}
	for (int i =1;i<=n;++i){
		int p,lf,rt;
		cin >> p >> lf >> rt;
		Tnode *former = node+p;
		Tnode *lfson = node+lf;
		Tnode *rtbro = node+rt;
		former->lfson = lfson;
		former->rtbro = rtbro;
		lfson->former = rtbro->former = former;
	}
	Tnode *root = node+1;
	while(root->former!=node)
		root = root->former;
	preorder(root,node);
	cout << endl;
	aftorder(root,node);
	cout << endl;
	hierachy(root,node);
	cout << endl;


    return 0;
}
