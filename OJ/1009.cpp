#include <cstdio>
#include <iostream>
using namespace std;


const int MAX = 100;
int main(){
    int m,n,k=0;
    int a[MAX],d[MAX];
    long long t[MAX];
    long long time;
    int prize,prize0=0;
    double earn = 0;
    cin >> m;
    for (int i=0;i<m;++i)
        cin >> t[i] >> a[i] >> d[i];
    for (int j=m-1;j>0;--j) for (int i=0;i<j;++i){
        if (t[i]>t[i+1]) {swap(t[i],t[i+1]);swap(a[i],a[i+1]);swap(d[i],d[i+1]);}
        }
    cin >> n;
    for (int i=0;i<n && k<m;++i){
        prize = prize0;
        cin >> time >> prize0;
        while (time > t[k]){
            if (d[k] == 1)
                earn += - 100 * prize * a[k] -((100 * prize * a[k] > 2500)? 100 *prize * a[k] * 0.002 : 5 ) - 1 - a[k] / 10;
            else if (d[k] == 2)
                earn += + 100 * prize * a[k] * 0.999 -((100 * prize * a[k] > 2500)? 100 * prize * a[k] * 0.002 : 5 ) - 1 - a[k] / 10;
            ++k;
        }
    }
    prize = prize0;
    while (time == t[k] && k < m){
            if (d[k] == 1)
                earn += - 100 * prize * a[k] -((100 * prize * a[k] > 2500)? 100 * prize * a[k] * 0.002 : 5 ) - 1 - a[k] / 10;
            else if (d[k] == 2)
                earn += + 100 * prize * a[k] * 0.999 -((100 * prize * a[k] > 2500)? 100 * prize * a[k] * 0.002 : 5 ) - 1 - a[k] / 10;
            ++k;
        }
    printf("%0.2f",earn);


    return 0;
}
