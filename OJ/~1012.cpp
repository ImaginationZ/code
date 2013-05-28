#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const long MAX = 200000;
long list[5][100];

long last[MAX+1];
long t[MAX+1];

int main() {
		long S,T,n;
		cin >> S >> T;
		for(long i=0;i<MAX+1;++i) last[i]=t[i]=1;
		for (long p=S;p<=T;++p){
			for(int k=1;k<=100&&p+p*k/100<=T;++k){
				if ((p*k)%100==0){
					long i = p+p*k/100;
					if(last[i]<last[p]+1){
						last[i]=last[p]+1;
						t[i] = t[p];
					}
					else if (last[p]+1==last[i]) {
						t[i]+=t[p];
					}
				}
			}
		}
		long max = 0;
		long ans = 0;
		for (long i=S;i<=T;++i){
			if (last[i] > max){
				max = last[i];
				ans = t[i];
			}
			else if (last[i] == max){
				ans += t[i];
			}

		}
		cout << max<<endl<<ans<<endl;
    return 0;
}
