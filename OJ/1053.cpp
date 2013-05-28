#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const long MAX = 20000;

struct coord{
	long x;
	long y;
	long z;
}map[MAX];

int line[100001];
int row[100001];

bool cmp(coord a,coord b){
	if (a.x < b.x) return 1;
	else if (a.x==b.x&&a.y<b.y) return 1;
	else return 0;
}

long search (long x,long y,long start,long end){
	coord key;
	key.x=x;
	key.y=y;
	long left,right;
	long mid;
	left=start;
	right=end;
	while(left <= right){
		mid=(left+right)/2;
		if (cmp(key,map[mid])) {
		right=mid-1;
		}
		else if(key.x>map[mid].x||(key.x==map[mid].x&&key.y>map[mid].y)){
			left=mid+1;
		}
		else
		return mid;
		}
	return -1;
}


long n;

void op(long num,long x,long y){
	if(num==0){
		swap(line[x],line[y]);
	}
	if(num==1){
		swap(row[x],row[y]);
	}
	if(num==2){
		long i = search(line[x],row[y],0,n-1);
		if(i>=0) printf("%d\n",map[i].z);
		else printf("0\n");
	}
}

int main() {
	for (int i=1;i<100001;++i){
		line[i] = row[i] = i;
	}
	cin >> n;
	for (long i=0;i<n;++i){
	long x,y,z;
	scanf ("%d %d %d",&x,&y,&z);
	map[i].x = x;
	map[i].y = y;
	map[i].z = z;
	}
	sort (map,map+n,cmp);

	long m;
	cin >> m;
	for (long i=0;i<m;++i){
		int a,x,y;
		scanf ("%d %d %d",&a,&x,&y);
		op(a,x,y);
	}

    return 0;
}
