#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=2e5+10;
int n,m;
int a[MAXN];
int main()
{
	freopen("jewel.in","r",stdin);
	freopen("jewel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1,l,r,res;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		res=0x3f3f3f3f;
		for (int j=l;j<=r;j++)
			for (int k=j+1;k<=r;k++)
				if (a[j]==a[k])
					res=min(res,k-j);
		if (res==0x3f3f3f3f) printf("-1\n");
		else printf("%d\n",res);
	}
}
