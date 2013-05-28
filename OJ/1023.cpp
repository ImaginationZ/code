#include <iostream>
using namespace std;

const int MAX=1000;
int sqr[MAX][MAX];

int main(){
    int n;
    cin >> n;
     for (int t=0;t<n;++t){
         int a,b;
        cin >> a >> b;
        for (int i=0;i<a;++i) for (int j=0;j<a;++j) cin >> sqr[i][j];
        if (b==0) for (int i=0;i<a;++i) {for (int j=0;j<a;++j) cout << sqr[i][a-j-1] << ' ';cout <<endl;}
        else if (b==1) for (int i=0;i<a;++i) {for (int j=0;j<a;++j) cout << sqr[a-i-1][j] << ' '; cout << endl;}
        else if (b==2) for (int i=0;i<a;++i) {for (int j=0;j<a;++j) cout << sqr[j][i] << ' '; cout <<endl;}
     }


}
