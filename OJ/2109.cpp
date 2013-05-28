
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const long MAX = 110000;
double a[MAX];

long find(double x,long start,long end){
	long mid=(start+end)/2;
	if (x<a[start]) return start;
	else if (start==end)	return start+1;
	else if (start+1==end){
		if(x>=a[end])return end+1;
		else return start+1;
	}
	else if (x>=a[mid]) return find(x,mid+1,end);
	else return (x,start,mid);

}

int main() {
	long n,k;
	cin >>n;
	for (long i=0;i<n;++i)
		cin >> a[i];
	cin >> k;
	for (long t=0;t<k;++t){
		double b,c;
		cin >> b>> c;
		cout << find(b*b/4/c,0,n-1)<<endl;

	}




    return 0;
}
