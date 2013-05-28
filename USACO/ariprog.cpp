/*
ID: frequen1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>

using namespace std;
const int MAX=10100;

int N,M;
long list[62555];

struct arithmetic{
	int a;
	int b;
};

arithmetic finds[MAX];
arithmetic newfind;

long find(long x,long start,long end){
	if (end==start){
			if(list[start]==x) return start;
			else return -1;
	}
	else if (end<start) return -1;
	else {
		long mid = (start+end)/2;
		if (list[mid]>=x) return find(x,start,mid);
		else return find(x,mid+1,end);
	}
}

bool findseq(long an,long b,long start,long end){
	int state = 1;
	long s=end;
	for (int i=0;i<N;++i){
		if((s=(find(an-i*b,start,s)))<0){
			state = 0;
			break;
		}
		}
	return state;
}

bool cmp(arithmetic x,arithmetic y){
	if (x.b>y.b) return 0;
	else if (x.b<y.b) return 1;
	else if (x.a>y.a) return 0;
	else return 1;
}


int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
	fin >> N >> M;
	int num=0,ans=0;
	for (int p=0;p<=M;++p) for (int q=p;q<=M;++q){
		list[num] = p*p + q*q;
		++num;
	}
	sort(list,list+num);
	int num0=num;
	for (int i=1;i<num0;++i)
		if(list[i]==list[i-1]){
			list[i-1]=130000;
			--num;
		}
	sort(list,list+num0);
	for (long i=num-1;i>0;--i)for(long j=i-1;j>0;--j){
		long a = list[i];
		long b = list[i]-list[j];
		if (a-(N-1)*b<0) break;
		if(findseq(a,b,0,i)){
			newfind.a = a-(N-1)*b;
			newfind.b = b;
			finds[ans] = newfind;
			++ans;
		}
	}
	sort (finds,finds+ans,cmp);
	for (long i=0;i<ans;++i)
	fout << finds[i].a << ' ' << finds[i].b << endl;
	if (ans == 0) fout << "NONE" << endl;
    return 0;
}
