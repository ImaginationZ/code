#include <iostream>
using namespace std;

const int MAX=20000;
long seq[MAX];
long sum[MAX] = {0};

int main(){
    long n,m,x,y;
    cin >> n;
    for (long i=0;i<n;++i){
        cin >> seq[i+1];
        sum[i+1] = sum[i] + seq[i+1];
    }
    cin >> m;
    for (long t=0;t<m;++t){
        cin >> x >> y;
        cout << sum[y] - sum[x-1] << endl;
    }


    return 0;
}
