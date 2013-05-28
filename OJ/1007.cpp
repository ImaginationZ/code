#include <cstdio>
#include <iostream>
using namespace std;


int main(){
    const int MAX=210;
    char a[MAX]={1},b[MAX]={1};
    int c[MAX]={0};
    int na,nb,n;
    gets(a);
    gets(b);
    for (na = 0;a[na]!='\0';++na);
    --na;
    for (nb = 0;b[nb]!='\0';++nb);
    --nb;
    for (int i=0;na>=0;--na,++i) c[i] = a[na] - '0';
    c[0] += b[nb] - '0'; --nb;
    c[1] += b[nb] - '0'; nb -= 2;
    for (int i=3;nb>=0;--nb,++i) c[i] += b[nb] - '0';
    if (c[0]>9) {c[0] %= 10; ++c[1];};
    if (c[1]>9) {c[1] %= 10; ++c[3];};
    for (n=3;n<MAX;++n) if(c[n]>9){
        c[n] %= 10;
        ++c[n+1];
    }
    for (n = MAX-1;c[n]==0;--n);
    for (;n>=0;--n) printf("%c",c[n] + '0');
    return 0;
}
