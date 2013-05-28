#include <iostream>
using namespace std;

int main(){
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    long long rab1 = 1,rab2 = 0,rab = 1;
        for (int i=0;i<n;++i){
            long long rab10 = rab1,rab20 = rab2;
            rab1 += (a - 1) * rab10 +b * rab20 + c * (rab - rab10 - rab20);
            rab2 += rab10 - rab20;
            rab += a * rab10 +b * rab20 + c * (rab - rab10 - rab20);
        }
        cout << rab;
        return 0;


}
