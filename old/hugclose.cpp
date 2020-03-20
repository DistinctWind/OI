#include <cstdio>
#include <iostream>
using namespace std;
const int LOGN=40;
const int MAXN=200010;
int num[MAXN],n,q;
int main()
{
	freopen("hugclose.in","r",stdin);
	freopen("hugclose.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++)
		scanf("%d",&num[i]);
	for (int i=1,x,l,r,res;i<=q;i++)
	{
		scanf("%d%d%d",&x,&l,&r);
		res=0;
		for (int j=l;j<=r;j++)
			res=max(res,x^num[j]);
		printf("%d\n",res);
	}
}
