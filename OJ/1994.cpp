#include <iostream>
using namespace std;

const int MAX = 1000;
int map[MAX][MAX];
const int UP = 8;
const int DOWN = 2;
const int LEFT = 4;
const int RIGHT = 5;
const int SEA = -1;
const int LAND = 0;
const int MARKED = 1;


void markland(int x,int y,int n,int m){
    if (x-1>=0 && map[x-1][y] == LAND){
        map[x-1][y] = MARKED;
        markland(x-1,y,n,m);
    }
    if (y-1>=0 && map[x][y-1] == LAND){
        map[x][y-1] = MARKED;
        markland(x,y-1,n,m);
    }
    if (x+1<m && map[x+1][y] == LAND){
        map[x+1][y] = MARKED;
        markland(x+1,y,n,m);
    }
    if (y+1<n && map[x][y+1] == LAND){
        map[x][y+1] = MARKED;
        markland(x,y+1,n,m);
    }
}

int main(){
    int n,m;
    int ans = 0;
    cin >> n >> m;
    for (int i=0;i<n;++i) for(int j=0;j<m;++j) cin >> map[i][j];
    for (int i=0;i<n;++i) for(int j=0;j<m;++j){
        if (map[i][j] == LAND){
            map[i][j] = MARKED;
            markland(i,j,n,m);
            ++ ans;
        }

    }
    cout << ans;
    return 0;
}
