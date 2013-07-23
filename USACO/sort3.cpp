/*
ID:frequen1
PROG:sort3
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAX = 1000;
int n;
int s[MAX+12];
int a[MAX+12];

int main(){
    int t12,t13,t21,t31,t23,t32;
    t12 = t13 =t21 = t31 =t23 =t32 =0;
    ifstream fin ("sort3.in");
    ofstream fout ("sort3.out");
    fin >> n;
    for (int i=0;i<n;++i){
        fin >> s[i];
        a[i] = s[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;++i){
        if(s[i]==1&&a[i]==2) ++t12;
        else if (s[i]==1&&a[i]==3) ++t13;
        else if (s[i]==2&&a[i]==1) ++t21;
        else if (s[i]==3&&a[i]==1) ++t31;
        else if (s[i]==3&&a[i]==2) ++t32;
        else if (s[i]==2&&a[i]==3) ++t23;
    }
    int q1 = min(t12,t21)+min(t13,t31);
    q1 += 2*(t12+t13-q1);
    q1 += min(t32,t23);
    fout << q1 << endl;
    return 0;
}
