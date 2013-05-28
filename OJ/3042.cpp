/*
ID: frequen1
PROG: test
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 3040;
int num[MAX];
int bigger[MAX][MAX] = {0};

int main() {
	int n,ans=0;
	cin >> n;
	for (int i=0;i<n;++i)
		cin >> num[i];
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j){
			if(num[j]>num[i]) {
				if (j==0) bigger[i][j] = 1;
				else if(bigger[i][j-1]!=0)bigger[i][j] = 1 + bigger[i][j-1];
				else bigger[i][j] = 1;
				}
			else if(j>0)	bigger[i][j] = bigger[i][j-1];
		}
	for (int i=0;i<n;++i) for (int j=i+2;j<n;++j)
		if(num[j]>num[i]) {
			ans+=bigger[j][j] - bigger[j][i];
		}
	cout << ans;
    return 0;
}
