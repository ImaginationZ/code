#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 100;
const int EMPTY=0;
const int BARY=-1;
const int START=2;
const int TREASURE=1;
const int MARKED=3;
const int UP = -8;
const int DOWN = -2;
const int LEFT = -4;
const int RIGHT = -6;

int map[MAX][MAX];
int trymap[MAX][MAX];

int startx,starty;

int find(int x,int y,int n,int m,int from=0){

    int leftans=0,rightans=0,upans=0,downans=0,ans;
    if (x-1>=0 && map[x-1][y] == TREASURE) {startx = x-1;starty = y;return 1;}
    else if (y-1>=0 && map[x][y-1] == TREASURE) {startx = x;starty = y-1;return 1;}
    else if (x+1<n && map[x+1][y] == TREASURE) {startx = x+1;starty = y;return 1;}
    else if (y+1<m && map[x][y+1] == TREASURE) {startx = x;starty = y+1;return 1;}
    else if (x-1>=0 && map[x-1][y] == EMPTY && from != UP){
        upans = find(x-1,y,n,m,DOWN) + 1;
    }
    else if (y-1>=0 && map[x][y-1] == EMPTY && from != LEFT){
        leftans = find(x,y-1,n,m,RIGHT) + 1;
    }
    else if (x+1<n && map[x+1][y] == EMPTY && from != DOWN){
        downans = find(x+1,y,n,m,UP) + 1;
    }
    else if (y+1<m && map[x][y+1] == EMPTY && from != RIGHT){
        rightans = find(x,y+1,n,m,LEFT) + 1;
    }
    ans = max(leftans,max(rightans,max(upans,downans)));
    if (ans == 0) return -1;
    else return ans;
}



int main(){
    int n,m,state = 0,ans = 0;
    cin >>n >>m;
    for (int i=0;i<n;++i) for(int j=0;j<m;++j) {
        cin >> map[i][j];
        if (map[i][j]==START){
            startx=i;
            starty=j;
        }
    }
    while(state != -1){
        ans += state;
        state = find (startx,starty,n,m);
        map[startx][starty] = EMPTY;

    }
    if (ans>0) cout << ans;
    else cout << -1;
    return 0;
}
