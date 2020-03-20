#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=110;
int f[MAXN],g[MAXN];
int n,h[MAXN],ans;
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++)
			if (h[j]<h[i])
				f[i]=max(f[i],f[j]+1);
	for (int i=n;i>=1;i--)
		for (int j=n+1;j>i;j--)
			if (h[j]<h[i])
				g[i]=max(g[i],g[j]+1);
	for (int i=1;i<=n;i++)
		ans=max(ans,f[i]+g[i]-1);
	printf("%d",n-ans);
}
