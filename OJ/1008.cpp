#include <cstdio>
#include <iostream>
using namespace std;

int workdays[10001][13][32];

bool yearleap(int year){
	return ((year%100>0&&year%4==0)||(year%400==0));
    }

int monthlen(int month,int year){
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:return 31;break;
        case 2:if (yearleap(year))return 29;else return 28;break;
        default :return 30;break;
    }
}


bool holidays(int month,int day){
    if (month==1 && day==1) return 1;
    else if (month == 5&&day>=1&&day<=3) return 1;
    else if (month == 10 &day>=1&&day<=7) return 1;
    else return 0;
}

int main(){
    workdays[1899][12][31]=0;
    int weekday,ans=0,yr,mh,dy,n,yr1,mh1,dy1,yr2,mh2,dy2;
    yr = 1900;
    mh = 1;
    dy = 0;
    weekday = 0;
        do{
            ++dy;
            weekday = (weekday+1)%7;
            if (dy > monthlen(mh,yr)) {
                dy=1;
                ++mh;
            }
            if (mh>12){mh=1;++yr;}
            if (weekday<6&&weekday>0&&(!holidays(mh,dy))) ++ans;
            workdays[yr][mh][dy] = ans;
        }while (yr<10000);
    cin >> n;
    for (int i=0;i<n;++i){
        scanf("%d-%d-%d",&yr1,&mh1,&dy1);
        scanf("%d-%d-%d",&yr2,&mh2,&dy2);
        --dy1;
        if(dy1==0){
            --mh1;
            if (mh1==0){
                mh1 = 12;
                --yr1;
            }
            dy1 = monthlen(mh1,yr1);
        }
        cout << workdays[yr2][mh2][dy2] - workdays[yr1][mh1][dy1] << endl;
    }


    return 0;
}
