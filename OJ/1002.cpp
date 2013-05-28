#include <iostream>
using namespace std;

const int MAX = 1100;
int L,W;
int bead[MAX][MAX];
int beads[MAX][MAX];
int main(){
	int a,b,n,max=0;
	cin >> L >> W;
	for (int i=0;i<L;++i) for(int j=0;j<W;++j)
		cin >> bead[i][j];
	cin >> a >> b;
	beads[0][0] = bead[0][0];
	for (int i=0;i<L;++i) for(int j=0;j<W;++j){
		if (i>0&&j>0)
			beads[i][j] = bead[i][j] + beads[i-1][j] + beads[i][j-1] - beads[i-1][j-1];
		else if (i>0&&j==0)
			beads[i][j] = bead[i][j] + beads[i-1][j];
		else if (i==0&&j>0)
			beads[i][j] = bead[i][j] + beads[i][j-1];
	}
	for (int i=0;i<=L-a;++i) for (int j=0;j<=W-b;++j){
		if (i>0&&j>0)
			n = beads[i+a-1][j+b-1] - beads[i-1][j+b-1] - beads[i+a-1][j-1] + beads[i-1][j-1];
		else if (i==0&&j>0)
			n = beads[i+a-1][j+b-1] - beads[i+a-1][j-1];
		else if (i>0&&j==0)
			n = beads[i+a-1][j+b-1] - beads[i-1][j+b-1];
		else if (i==0&&j==0)
			n = beads[i+a-1][j+b-1];
		if (n>max) max = n;
	}

	cout << max << endl;

    return 0;
}
