#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 101;
int map[MAX][MAX];

inline bool valid(int i,int j,int l){
	return (map[i][j]==0&&i<l&&i>=0&&j<l&&j>=0);
}

void re(int i,int j,int l){
	map[i][j]=2;
	if(valid(i+1,j,l))map[i+1][j] = 3;
	if(valid(i-1,j,l))map[i-1][j] = 3;
	if(valid(i,j-1,l))map[i][j-1] = 3;
	if(valid(i,j+1,l))map[i][j+1] = 3;
}

int main() {
	int l;
	cin>>l;
	for (int i=0;i<l;++i)for (int j=0;j<l;++j)
		cin >> map[i][j];
	int t=0;
	bool flag=1;
	while(flag){
		flag = 0;
		for (int i=0;i<l;++i)for (int j=0;j<l;++j)
			if (map[i][j]==1) re(i,j,l);
		for (int i=0;i<l;++i)for (int j=0;j<l;++j){
			if(map[i][j]==0) ++flag;
			if(map[i][j]==3) map[i][j]=1;
		}
		++t;

	}
	cout << t;
    return 0;
}
