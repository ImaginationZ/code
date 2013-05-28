#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 151;

int map[MAX][MAX] = {0};

struct v{
	int x;
	int y;
	v(){x=0;y=1;}
	void turn(){int tmp=x;x=y;y=-tmp;}
};

inline bool valid(int i,int j,int n){
	return (i>=0&&i<n&&j>=0&&j<n&&map[i][j]==0);
}
int main() {
	int n;
	cin >> n;
	int i=0,j=0;
	v z;
	for (int k=1;k<=n*n;++k){
		map[i][j] = k;
		if(!valid(i+z.x,j+z.y,n))
			z.turn();
		i+=z.x;
		j+=z.y;
	}
	for (i=0;i<n;++i){
		for (j=0;j<n;++j)
			cout << setw(6) << map[i][j];
		cout << endl;
	}
    return 0;
}
