#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int x[10005],y[10005],t[10005],a[10005],d[10005];

int find(int r,int t)
{
	int l=0;
	while (l<r)
	{
		int mid=(l+r+1)/2;
		if (x[mid]>t) r=mid-1;
		else l=mid;
	}
	return y[l];
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	int m;
	cin>>m;
	for (int i=0;i<m;i++)
		cin>>t[i]>>a[i]>>d[i];
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	double ans=0;
	for (int i=0;i<m;i++)
	{
		int money=find(n-1,t[i]);
		int cost=money*a[i];
		if (d[i]==1) ans-=100.*cost;
		else ans+=99.9*cost;
		ans-=max(0.2*cost,5.);
		ans-=a[i]/10.;
		ans-=1.;
	}
	printf("%.2f\n",ans);
	return 0;
}
