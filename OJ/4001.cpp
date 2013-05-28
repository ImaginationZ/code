#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	long long a=0,b=0;
	long long *now = &a;
	char c;
	while((c=getchar())!=EOF){
		if (c==' ');
		else if (c=='+') now = &b;
		else {
			*now *= 10;
			*now += c - '0';
			cout << *now << endl;
		}
	}
	long long ans = a+b;
	if (ans > 100000000) cout << "Large"<<endl;
	else cout << ans <<endl;


    return 0;
}
