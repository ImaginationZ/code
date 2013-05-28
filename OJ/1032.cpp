
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int number[1000]={0};

int main() {
	int m,n,p;
	cin >> m >> n;
	if (m==0) cout << n+1;
	else if (m==1) cout << n+2;
	else if (m==2) cout << 2*n+3;
	else if (m==3) {
		number[0] = 5;
		p=1;
		for (int i=0;i<n;++i){
			for (int j=0;j<p;++j) number[j] *= 2;
			number[0] += 3;
			for (int j=0;j<p-1;++j){
				number[j+1]+=number[j]/10;
				number[j]%=10;
			}
			if (number[p-1]>9){
				number[p]+=number[p-1]/10;
				number[p-1]%=10;
				++p;
			}
		}
		for (int i=p-1;i>=0;--i) cout << number[i];
	}


    return 0;
}
