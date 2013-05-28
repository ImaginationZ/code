#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100001;

int tree[MAX];

int find(int x,int from,int max){
	if (from>max) return -1;
	if (tree[from]>x) return tree[from];
	int a = find(x,2*from,max);
	int b = find(x,2*from+1,max);
	if(a==-1) return b;
	if(a<b) return a;
	if (b==-1) return a;
	return b;
}

void findmin(int x,int max){
	cout << find(x,1,max);
}

void decrease(int i,int j){
	tree[i] -= j;
	while(tree[i]<tree[i/2]&&i>0){
		swap (tree[i],tree[i/2]);
		i/=2;
	}
}

int main() {
	int n,a,b;
	char op[50];
	cin >> n;
	for (int i=1;i<=n;++i)
		scanf("%d",tree+i);
	sort(tree+1,tree+n+1);
	while(scanf("%s",op)){
		if(0==strcmp(op,"findmin")){
			scanf("%d",&a);
			findmin(a,n);
		}
		else if(0==strcmp(op,"decrease")){
			scanf("%d%d",&a,&b);
			decrease(a,b);
		}
	}


    return 0;
}
