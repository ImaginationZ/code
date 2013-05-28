#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int inf=0x3fffffff;
const int MAX = 150;
struct node{
	   int x,y,time;
};
int N,M;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int map[MAX][MAX],vis[MAX][MAX];
node p[10];
node save[10];
int cnt;
void bfs(int x,int y){
	queue<node>q;
	node temp,cur;
	temp.x=x; temp.y=y; temp.time=0;
	q.push(temp);
	vis[x][y]=1;
	while(!q.empty()){
		 cur=q.front();
		 q.pop();
		 for(int i=0;i<4;i++){
			 int xx=cur.x+dir[i][0],yy=cur.y+dir[i][1];
			 if(xx>=1 && xx<=N && yy>=1 && yy<=M && !vis[xx][yy] && map[xx][yy]!=-1){
				  vis[xx][yy]=1;
				  temp.x=xx; temp.y=yy;temp.time=cur.time+1;
				  q.push(temp);
				  if(map[xx][yy]==1 || map[xx][yy]==2){
					  save[cnt++]=temp;
				  }
			 }
		 }

	}
}
int mm[10][10],mark[10],Min,num;
int dfs(int v,int c,int time){
	mark[v]=1;
	if(c==num){
		if(time<Min)
			Min=time;
	}
	for(int i=0;i<=num;i++){
		if(!mark[i] && mm[v][i]!=inf){
			 mark[i]=1;
			 dfs(i,c+1,time+mm[v][i]);
			 mark[i]=0;
		}
	}
}
int main(){
	cin >> N >> M;
    num=0;
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++){
        cin >> map[i][j];
        if(map[i][j]==2){
            p[0].x=i; p[0].y=j;
        }
        else if(map[i][j]==1){
            p[++num].x=i; p[num].y=j;
        }}
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)
            mm[i][j]=inf;
    for(int i=0;i<=num;i++){
        memset(vis,0,sizeof(vis));
        cnt=0;
        bfs(p[i].x,p[i].y);
        for(int j=0;j<cnt;j++){
            int k;
            for(k=0;k<=num;k++)
                if(save[j].x==p[k].x && save[j].y==p[k].y) break;
                mm[i][k]=save[j].time;
            }
		 }
    memset(mark,0,sizeof(mark));
    Min=inf;
    dfs(0,0,0);
    if(Min==inf)
        cout << "-1" << endl;
    else
        cout << Min << endl;

	return 0;
}
