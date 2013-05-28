
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 1010;

int w[MAX];
int c[MAX];
int f[MAX][10010];

int main() {
	int v,n;
	cin >> v >> n;
	for (int i=0;i<n;++i)
		cin >>c[i]>>w[i];
	for (int h=0;h<=v;++h){
		f[0][h] = h/c[0]*w[0];
	}
	for (int i=1;i<n;++i){
		for (int h=0;h<=v;++h){
			if(h<c[i]) f[i][h] = 0;
			else{
				f[i][h] = f[i-1][h];
				if (f[i][h]<f[i][h-c[i]]+w[i])
					f[i][h] = f[i][h-c[i]]+w[i];
			}
		}
	}
	cout << f[n-1][v];
    return 0;
}
