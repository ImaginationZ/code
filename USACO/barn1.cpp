/*
ID: frequen1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

const long MAX = 250;
long barn[MAX];
long d[MAX];

int main() {
	long m,s,c,ans = 0;
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
	fin >> m >> s >> c;
	for (long i = 0;i<c;++i)
		fin >> barn[i];
	sort(barn,barn+c);
	for (long i=0;i<c-1;++i)
		d[i] = barn[i+1]-barn[i];
	sort(d,d+c-1);
	if(c>m){
	for (long i = c-2;i>c-1-m;--i)
		ans += d[i]-1;
	ans = s- ans - (barn[0]-1)-(s-barn[c-1]);
	fout << ans << endl;
	}
	else fout << c << endl;



    return 0;
}
