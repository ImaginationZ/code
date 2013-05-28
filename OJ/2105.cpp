#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const long MAX = 1000100;
struct point {
	long long h;
	long left;
	long right;
}p[MAX];

int main() {
	long n;
	long long max = 0;
	cin >> n;
	for (long i=0;i<n;++i){
		cin >> p[i].h;
		p[i].left = p[i].right = i;
	}
	for(long i=0;i<n;++i){
		while(p[i].left-1&&p[p[i].left-1].h>=p[i].h) --p[i].left;
		while(p[i].right+1<n&&p[p[i].right+1].h>=p[i].h) ++p[i].right;
		if(p[i].right+1<n)p[p[i].right+1].left = i;
	}
	for(long i=0;i<n;++i){
		long long area = p[i].h*(p[i].right-p[i].left+1);
		if (area > max)	max =area;
	}
	cout << max;
    return 0;
}
