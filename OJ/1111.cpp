#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

struct node{
	char key;
	node *lf;
	node *rt;
	node(int i){key=i;lf=rt=NULL;}
};

int find(char ch,char *str){
	for (int i=0;i<strlen(str);++i)
		if (str[i]==ch) return i;
		return -1;
}

node *maketree(char *pre,char *mid,int len){
	if (len<=0) return NULL;
	node *root = new node(*pre);
	if (len==1) return root;
	int rt = find (*pre,mid);
	root->lf = maketree(pre+1,mid,rt);
	root->rt = maketree(pre+1+rt,mid+1+rt,len-1-rt);
	return root;
}

void aftorder(node *root){
    if(root==NUll) return;
    else {
        aftorder(root->lf);
        aftorder(root->rt);
        cout << root->key;
    }
}


int main() {
	char pre[30],mid[30];
	scanf ("%s%s",pre,mid);
	node* root = maketree(pre,mid,strlen(pre));
    aftorder(root);
    return 0;
}
