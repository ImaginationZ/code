#include <iostream>
#include <cstdio>
using namespace std;


const int MAX = 111111;
int sort[MAX] = {-1};

int main(){
    int n,number,j;
    cin >> n;
    for (int i=0;i<n;++i){
        scanf("%d",&number);
        for (j=0;sort[j] < number && sort [j] != -1;++j);
        for (int k=i;k>=j;--k) sort[k+1]=sort[k];
        sort[j] = number;
    }
    for (int i=0;sort[i]!= -1;++i) cout << sort[i] << ' ';
    return 0;
}
