#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

long long count(long long n){
	if (n<10) return n;
	else if (n<100)	return 9+n/11;
	else {
		long long a=n,b=n%10;
		int p=1;
		while (a>9) {
			a/=10;
			++p;
		}
		return(a-1)*pow(10,p-2)+(n-a*pow(10,p-1))/10+((a<=b)?1:0)+9+(pow(10,p-2)-1);
	}
}

int main() {
	long long l,r,ans;
	cin >> l >> r;
	cout << count(r) - count(l-1)<<endl;


    return 0;
}
