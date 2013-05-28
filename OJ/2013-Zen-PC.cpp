#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 10000;
int candy[MAX] = {0};

int eat(int start,int k,int n){
    int p=start-1,end,eat = 1;
    while (true){
    for (int i=0;i<k;++i) {
        do{
            ++p;
            if(p>8 * n) p = 1;
        }while (candy[p]==0 && p!= start);
            if (p==start) break;
    }
    if (p==start) break;
    for (int i=0;i<k;++i) {
        do{
            ++p;
            if(p>8 * n) p = 1;
        }while (candy[p]==0 && p!= start);
        candy[p] = 0;
        end = p;
        if (p==start) break;
    }
    if (p==start) break;
    }
    return end;
}

int main(){
    int m,end,start=1;
    cin >> m;
    for (int i=0;i<m;++i){
        int n;
        int k[7];
        cin >> n;
        for (int j=0;j<n;++j) cin >> k[j];
        for (int j=1;j<= 8 * n;++j) candy[j] = 1;
        for (int j=8*n+1;j<MAX;++j) candy[j] = 0;
        for (int j=0;j<7;++j)
            cout << (end = eat(start,k[i],n)) << endl;
            do{
                ++end;
                if(end>8 * n) end = 1;
            }while (candy[end]==0 && end != start);
            start = end;





    }


    return 0;
}
