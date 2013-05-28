#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

const int MAX = 12000;
long upper[MAX],lower[MAX];

bool cmp(long a,long b){
	if(a>b)return 1;
	else return 0;
}

int main(){
	int n,m;
	cin >> n >> m ;
	for (int i=0;i<n;++i)
		cin >> upper[i];
	for (int i=0;i<m;++i)
		cin >> lower[i];
	sort(upper,upper+n,cmp);
	sort(lower,lower+m,cmp);
	int p=0,add=0;
	for (int i=0;i<n;++i){
		while (p<m&&lower[p]>=upper[i]){
			++p;
		}
		if(p<m){
			++add;
			++p;
		}
	}
	cout << n+add;
    return 0;
}
