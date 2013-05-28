#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n,left;
    const int MAX = 120;
    char a[MAX];
    cin >> n;
    for (int i=0;i<n;++i){
        left = 0;
        cin >> a;
        for (int j=0;a[j]!='\0';++j){
            if (a[j] == '(') ++left;
            else if (a[j] == ')') --left;
            if (left < 0){cout << "NO" << endl;break;}
        }
        if (left > 0) cout << "NO" << endl;
        else if (left == 0) cout << "YES" << endl;
    }
    return 0;
}
