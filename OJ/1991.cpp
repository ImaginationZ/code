#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const long MAX = 110000;
double point[MAX];

long tryd(double d,long n){
    double p = point[0];
    long k = 1;
    for (long i = 0;i<n;++i){
        if (point[i]>p+2*d){
            ++k;
            p = point[i];
        }

    }
    return k;
}

int main(){
    long n,k;
    double c,mid,mid0,a=0,b=10000000;
    mid = (a+b)/2;
    mid0 = 0;
    cin >> n >> k;
    for (long i=0;i<n;++i)
        cin >> point[i];
    while (abs(mid0-mid)>0.0000000001){
        mid = (a+b)/2;
        if ((c=tryd(mid,n))>k) a = mid;
        else if (c<=k) b = mid;
        mid0 = (a+b)/2;
    }
    printf("%.6f\n",mid);
    return 0;
}
