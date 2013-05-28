#include <iostream>
using namespace std;

const int MAX = 20000;

int flb[MAX];
int state = 0;
int start;
int end;
int cirle;

void findcircle(){
    flb[0] = flb[1] = 1;
    for (int i=2;i<MAX & state == 0;++i){
        flb[i] = (flb[i-1] + flb[i-2]) % 2010;
        for (int j=1;j<i;++j) if(flb[j]==flb[i] && flb[j-1] == flb[i-1]) {
            state = 1;
            start = j-1;
            end = i-2;
        }
    }
}

int main(){
    char number[50];
    int p = 0;
    findcircle();
    cirle = end - start + 1;
    cin >> number;
    for (int i=0;number[i]!= '\0';++i){
        p = (p*10 + number[i] - '0') % cirle;
    }
    cout << flb[p+start-1];


}
