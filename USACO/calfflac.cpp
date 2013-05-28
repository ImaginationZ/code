/*
ID: frequen1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 20010;
char s[MAX];

bool judge(char c){
	if (c<='z' && c>='a') return 1;
	else if (c<='Z' && c>= 'A') return 1;
	else return 0;
}

bool compare(char a,char b){
	if (a==b || a-b=='Z'-'z' || a-b == 'z' - 'Z') return 1;
	else return 0;
}

int main() {
	int c;
	int pl,pr,n=0;
	int max=0;
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
	while ((c = fin.get())!=EOF){
		s[n] = c;
		++n;
	}
	for (int i=0;i<n;++i){
			int p1=i,p2=i,num=0;
			while(p1>=0&&p2<n&&compare(s[p1],s[p2])){
				++num;
				do{
					--p1;
				}while (!judge(s[p1])&&p1>=0);
				do{
					++p2;
				}while(!judge(s[p2])&&p2<n);
			}
			if (!judge(s[i])) num = 2*num - 2;
			else num = 2*num - 1;
			if (num>max){
				max = num;
				do{
					++p1;
				}while (!judge(s[p1]));
				do{
					--p2;
				}while(!judge(s[p2]));
				pl=p1;
				pr=p2;
			}
	}
	fout <<max << endl;
	for (int i=pl;i<=pr;++i)
		fout << s[i];
	fout <<endl;


    return 0;
}
