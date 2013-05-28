#include <iostream>
using namespace std;




const int MAX=20000;

int main(){
    int n;
    cin >> n;
    long left[n],right[n],length=0,left0;
    for (int i=0;i<n;++i)
        cin >> left[i] >> right[i];
    for (int j=n-1;j>0;--j) for (int i=0;i<j;++i){
        if (left[i]>left[i+1]) swap(left[i],left[i+1]);
        if (right[i]>right[i+1]) swap(right[i],right[i+1]);
        }
    left0 = left[0];
    for (int i=0;i<n-1;++i) if (right[i]<left[i+1]) {
        length += right[i] - left0;
        left0 = left[i+1];
    }
        length += right[n-1] - left0;
    cout << length;
return 0;
}
