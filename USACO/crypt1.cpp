/*
ID: frequen1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int N;
int digits[10];

bool find(int x){
	int state = 0;
	for (int i=0;i<N;++i)
		if (digits[i] == x){
			state = 1;
			break;
		}
	return state;
}

bool  judge(int x,int base){
	if (x>=pow(10,base)||x<pow(10,base-1)) return 0;
	else {
		int state = 1;
		for (int i=0;i<base;++i){
			if (!find(x%10)) {
				state = 0;
				break;
			}
			x /= 10;
		}
	return state;
	}


}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
	int ans=0;
	fin >> N;
	for (int i=0;i<N;++i){
		fin >> digits[i];
	}
	for (int i11=0;i11<N;++i11)
		for (int i12=0;i12<N;++i12)
			for (int i13=0;i13<N;++i13)
				for (int i21=0;i21<N;++i21)
					for (int i22=0;i22<N;++i22){
						int a1 = (100*digits[i11]+10*digits[i12]+digits[i13])*digits[i22];
						int a2 = (100*digits[i11]+10*digits[i12]+digits[i13])*digits[i21];
						int a3 = a1 + a2*10;
						if (judge(a1,3)&&judge(a2,3)&judge(a3,4)) ++ans;
					}
	fout << ans << endl;
    return 0;
}
