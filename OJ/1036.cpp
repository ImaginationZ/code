#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const long MAX = 120000;
int A[MAX];
long N;
long wait;

int main() {
    cin >> N;
    for (long i=0;i<N;++i)
    	cin >> A[i];

	if (N>3){
		long q[3]={0};
		long t = 0;
		for (long i=0;i<N;++i){
			int j = i%3;
			t += q[j];
			q[j] += A[i];
 		}
 		cout<<t<<' '<<max(q[0],max(q[1],q[2]))<<endl;

		t = 0;
		q[0]=q[1]=q[2]=0;
		for (int i=0;i<N;++i){
		if (q[0]<=q[1] && q[0]<=q[2]){
			t+=q[0];
			q[0]+=A[i];
		}
		else if (q[1]<=q[2]){
			t+=q[1];
			q[1]+=A[i];
		}
		else{
			t+=q[2];
			q[2]+=A[i];
		}
	}
	cout<<t<<' '<<max(q[0],max(q[1],q[2]))<<endl;
	}
	else if (N==1){
		cout << 0 << " " << A[0]<<endl;
		cout << 0 << " " << A[0]<<endl;
	}
	else if (N==2){
		cout << 0 << " " << max(A[0],A[1])<<endl;
		cout << 0 << " " << max(A[0],A[1])<<endl;
	}


    return 0;
}
