#include<iostream>
#include<fstream>
using namespace std;
int n, m;
bool belong[205][205];
int size[205];
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> size[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= size[i]; j++){
			int x;
			cin >> x;
			belong[i][x] = true;
		}
	cin >> m;
	for (int i = 1; i <= m; i++){
		char ch;
		int x, y;
		cin >> ch >> x >> y;
		switch (ch){
			case '+':{
				for (int i = 0; i < 205; i++)
					if (belong[y][i]) belong[x][i] = true;
				break;
			}
			case '-':{
				for (int i = 0; i < 205; i++)
					if (belong[y][i]) belong[x][i] = false;
				break;
			}
			case '*':{
				for (int i = 0; i < 205; i++)
					if (belong[x][i] && belong[y][i]) belong[x][i] = true;
					else belong[x][i] = false;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 205; j++)
			if (belong[i][j]) cout << j << ' ';
		cout << '\n';
	}
    
}
