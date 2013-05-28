#include<cstdio>
#include<iostream>
#include<cstring>
#define MaxLen 10005
#define MaxYear 10000
#define MaxMonth 13
#define MaxDay 32
using namespace std;

int n,sy,sm,sd,ey,em,ed,ans,WorkDays[MaxYear][MaxMonth][MaxDay],days[MaxMonth]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
char ch[MaxLen];
bool isWorkDay[MaxYear][MaxMonth][MaxDay];
int totalWorkDay[MaxYear][MaxMonth][MaxDay];

bool isLeapYear(int Year){
	return ((Year%100>0&&Year%4==0)||(Year%400==0));
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int now=0,weekDay=1;
	for (int y=1;y<=9999;++y){
		if (isLeapYear(y))days[2]=29;else days[2]=28;
		for (int m=1;m<=12;++m)
		for (int d=1;d<=days[m];++d){
			if ((weekDay>5)||(m==1&&d==1)||(m==5&&d>=1&&d<=3)||(m==10&&d>=1&&d<=7)){
				totalWorkDay[y][m][d]=now;
			}else{
				isWorkDay[y][m][d]=true;
				++now;
				totalWorkDay[y][m][d]=now;
			}
			weekDay+=1;
			if (weekDay>7)weekDay=1;
		}
	}
	scanf("%d\n",&n);
	int tmp;
	for (int i=1;i<=n;++i){
		gets(ch);
		for (int i=0;i<strlen(ch);++i)if (!(ch[i]>='0'&&ch[i]<='9'))ch[i]=' ';
		sscanf(ch,"%d%d%d%d%d%d",&sy,&sm,&sd,&ey,&em,&ed);
		printf("%d\n",totalWorkDay[ey][em][ed]-totalWorkDay[sy][sm][sd]+(int)isWorkDay[sy][sm][sd]);
	}
	return 0;
}
