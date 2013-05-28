#include  <iostream>

using namespace std;

const long MAX = 2000000;
int a[MAX];


int main(){
	long n;
	cin >> n;
	for (long i=0;i<n;++i)
		cin >> a[i];
	long max = 0;
	long add = 0;
	long num;
	for (long i=0;i<n;++i){
		add+=a[i];
		++num;
		if (add<0) {add=0;num=0;}
		if (add>max&&num>1) max = add;
	}
	if (max>0) cout << max ;
	else cout << "Game Over"<<endl;
	return 0;
}
