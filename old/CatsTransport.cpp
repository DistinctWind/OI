#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=1e5+1;
int n,m,p,q[MAXN];
long long d[MAXN],a[MAXN],s[MAXN],g[MAXN],f[101][MAXN];
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&p);
	int temp;
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&temp);
		d[i]=d[i-1]+temp;
	}
	int aim;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&aim,&temp);
		a[i]=temp-d[aim];
	}
	sort(a+1,a+1+m);
	for (int i=1;i<=m;i++)
		s[i]=s[i-1]+a[i];
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	int l,r;
	for (int i=1;i<=p;i++)
	{
		for (int j=1;j<=m;j++)
			g[j]=f[i-1][j]+s[j];
		q[l=r=1]=0;
		for (int j=1;j<=m;j++)
		{
			 while (l<r&&g[q[l+1]]-g[q[l]]<=a[j]*(q[l+1]-q[l])) l++;
			 f[i][j]=min(f[i-1][j],g[q[l]]+a[j]*(j-q[l])-s[j]);
			 if (g[j]>=0x3f3f3f3f3f3f3f3fll) continue;
			 while (l<r&&(g[j]-g[q[r]])*(q[r]-q[r-1])<=(g[q[r]]-g[q[r-1]])*(j-q[r])) r--;
			 q[++r]=j;
		}
	}
	cout<<f[p][m]<<endl;
}
//LOJ https://loj.ac/problem/10187
