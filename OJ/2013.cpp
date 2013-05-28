#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 100000;
int circle[MAX],trans[MAX];


int eat(int k,int n){
    int p=-1,end=-1,t=0;
    while (true){
    for (int i=0;i<k;++i) {
        ++p;
        if (p>=n) break;
    }
    if (p>=n) break;
    --p;
    for (int i=0;i<k;++i) {
        ++p;
        if (p>=n) break;
        circle[p] = -circle[p];
        end = p;
        }
    if (p>=n) break;
    }
    return end;
}

int merge(int n,int start){
    int k=0;
    for (int i=start;i<n;++i){
        if (circle[i]>0) {trans[k] = circle[i];++k;}
    }
    for (int i=0;i<start;++i){
        if (circle[i]>0) {trans[k] = circle[i];++k;}
    }
    for (int i=0;i<k;++i){
        circle[i] = trans[i];
    }
    return k;
}


int main(){
    int ans=0,m,end;
    cin >> m;
    for (int i=0;i<m;++i){
        int n;
        int k[7];
        cin >> n;
        n *= 8;
        for (int j=0;j<7;++j) cin >> k[j];
        for (int j=0;j< n;++j) circle[j] = j+1;
        for (int j=0;j<7;++j){
            end = eat(k[j],n);
            if (end >= 0){
                ans = -circle[end];
                n = merge(n,(end==n-1)?0:end+1);
            }
        }
        if (ans!=0) cout << ans << endl;
    }
    return 0;

    }
