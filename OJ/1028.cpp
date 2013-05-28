#include <iostream>
#include <string>

using namespace std;

const int BEGIN = 1;
const int END = 2;
const int IF = 3;
const int THEN= 4;
const int ELSE =5;
const int MAX =200;


int s[MAX];

bool judge(int a,int b){
	if (a==b) return 0;
	bool state = 1;
	int p,q,c=0,d=0,x,y;
	for (int i=a;i<=b;++i){
			if (c<0) {
				state = 0;
				break;
			}
			if(c==0&&s[i]==BEGIN) p=i;
			if(s[i]==BEGIN)++c;
			if(s[i]==END)--c;
			if(s[i]==END&&c==0) {
				q=i;
				if(q>p+1)state = judge(p+1,q-1);
				if(!state)break;
			}
	if (c>0) state = 0;
	}
	for (int i=a;i<=b;++i){
		if (s[i])


	}


}

int main(){
	int n;
	cin >> n;
	string sen;
	for (int i=0;i<n;++i){
	cin >>sen;
	if (sen=="begin") s[i]=BEGIN;
	if (sen=="end") s[i]=END;
	if (sen=="if") s[i]=IF;
	if (sen=="else") s[i]=ELSE;
	if (sen=="then") s[i]=THEN;
	}


	return 0;
	}
