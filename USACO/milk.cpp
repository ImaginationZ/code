/*
ID: frequen1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 5010;

struct person{
    int p;
    long amount;
};

person sells[MAX],trans[MAX];

void sort(int start,int end){
    int mid,p0,p1,p2;
    if (start != end){
        mid = (start+end)/2;
        sort(start,mid);
        sort(mid+1,end);
        p0=p1=start;
        p2=mid+1;
        while(p1<=mid&&p2<=end){
            if (sells[p1].p<=sells[p2].p) trans[p0++] = sells[p1++];
            else trans[p0++] = sells[p2++];
        }
        while(p1<=mid)
            trans[p0++] = sells[p1++];
        while(p2<=end)
            trans[p0++] = sells[p2++];
        for (int i=start;i<=end;++i)
            sells[i] = trans[i];
    }


}


int main(){
    long long N;
    long long ans=0,amount=0;
    int m,k=0;
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    fin >> N >> m;
    if (N>0){
    for(int i=0;i<m;++i)
        fin >> sells[i].p >> sells[i].amount;
    sort(0,m-1);
    while (amount<N){
        amount += sells[k].amount;
        ans += sells[k].amount * sells[k].p;
        ++k;
    }
    ans -= (amount - N) * sells[k-1].p;
    fout << ans << endl;}
    else fout << "0" <<endl;
    return 0;
}
