/*
ID: frequen1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 21*21*21;
struct state{
	int a;
	int b;
	int c;
}possible[MAX];


int stateC[20];
int A,B,C;

bool change(int& from,int& to,int ct){
	if (from==0) return 0;
	else if (from+to<ct){
		to += from;
		from = 0;
		return 1;
	}
	else{
		from -= ct-to;
		to = ct;
		return 1;
	}
}

bool find(state x,int n){
	int state = 0;
	for (int i=0;i<n;++i){
		if (x.a==possible[i].a&&x.b==possible[i].b&&x.c==possible[i].c){
			state = 1;
			break;
		}
	}
	return state;
}

bool added(int x,int num){
	int state = 0;
	for (int i=0;i<num;++i){
		if (x==stateC[i]){
			state = 1;
			break;
		}
	}
	return state;
}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    int n=1,p=1,num=0;
    state x;
    fin >>A>>B>>C;
    possible[0].a = possible[0].b = 0;
    possible[0].c = C;
	for (int i =0;i<n;++i){
		x= possible[i];
		if (change(x.a,x.b,B)&&!find(x,n)){
			possible[n] = x;
			++n;
		}
		x= possible[i];
		if (change(x.b,x.a,A)&&!find(x,n)){
			possible[n] = x;
			++n;
		}
		x= possible[i];
		if (change(x.a,x.c,C)&&!find(x,n)){
			possible[n] = x;
			++n;
		}
		x= possible[i];
		if (change(x.c,x.a,A)&&!find(x,n)){
			possible[n] = x;
			++n;
		}
		x= possible[i];
		if (change(x.b,x.c,C)&&!find(x,n)){
			possible[n] = x;
			++n;
		}
		x= possible[i];
		if (change(x.c,x.b,B)&&!find(x,n)){
			possible[n] = x;
			++n;
		}
	}
	for (int i=0;i<n;++i){
		if (possible[i].a==0&&!added(possible[i].c,num)){
			stateC[num] = possible[i].c;
			++num;
		}
	}
	sort(stateC,stateC+num);
	for (int i =0;i<num-1;++i)
		fout << stateC[i]<<' ';
	fout <<stateC[num-1]<<endl;

    return 0;
}
