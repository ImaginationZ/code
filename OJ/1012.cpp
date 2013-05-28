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
		for (long p=T-1;p>=S;--p){
			for(long i=p+1;i<=T&&i<=2*p;++i){
				if ((100*i)%p==0){
					if(last[i]+1>last[p]){
						last[p]=last[i]+1;
						t[p] = t[i];
					}
					else if (last[i]+1==last[p]) {
						t[p]+=t[i];
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
