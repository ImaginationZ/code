#include <cstdio>
#include <iostream>
using namespace std;


const int MAX = 100;
const int MAX2 = 12000;
long tim[MAX2];
int prize[MAX2];
int a[MAX],d[MAX];
long t[MAX];

int main(){
    int m,n;
    double cost;
    double earn = 0;
    cin >> m;
    for (int i=0;i<m;++i)
        cin >> t[i] >> a[i] >> d[i];
    cin >> n;
    for (int i=0;i<n;++i)
        cin >> tim[i] >> prize[i];
    tim[n] = 200000000;
    for (int i=0;i<m;++i) for (int j=0;j<n;++j){
        if (t[i]<tim[j+1]){
            cost = prize[j] * a[i];
            if (d[i]==1) earn -= 100. * cost;
            else if (d[i]==2) earn += 99.9*cost;
            earn -= 1 + max(cost*0.2,5.) + a[i]/10.;
            break;}
    }

    printf("%.2f",earn);


    return 0;
}
