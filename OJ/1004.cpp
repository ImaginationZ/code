#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	long long m,t;
	int u,f,d;
	cin >> m >> t >> u >> f >> d;
	long long x=0,max=0;
	for (long long i=0;i<t;++i){
		char si;
		cin >> si;
		if(si=='f') max+=2*f;
		else max+=u+d;
		if (max>m) break;
		x++;
	}
	cout << x;

    return 0;
}
