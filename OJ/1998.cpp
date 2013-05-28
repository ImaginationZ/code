#include <iostream>
using namespace std;

const long MAX = 200000;
int pos[MAX];
int trans[MAX];

void sort(int num[],long start,long end){
    long p1,p2;
    if(end - start == 1) {if(num[start] > num[end]) swap(num[start],num[end]);}
    else if (end != start){
        sort (num,start,(start+end)/2);
        sort (num,(start+end)/2+1,end);
        p2 = (start+end)/2+1;
        p1 = start;
        for (long p=start;p<=end;++p){
            if (p1 <= (start+end)/2 && p2 <= end){
            if(num[p1]>num[p2]){
                trans[p] = num[p2];
                ++p2;
        }
            else {
                trans[p] = num[p1];
                ++p1;
            }
            }
            else if (p1 > (start+end)/2){
                trans[p] = num[p2];
                ++p2;
            }
            else if (p2 > end){
                trans[p] = num[p1];
                ++p1;
            }
    }
    for (long p = start;p<=end;++p) num[p] = trans[p];
}
}

int main(){
    long n,ans=0;
    cin >> n;
    for (long i=0;i<n;++i) cin >> pos[i];
    sort (pos,0,n-1);
    for (long i=0;i<n/2;++i) ans += pos[n-1-i] - pos[i];
    cout << ans;
    return 0;
}
