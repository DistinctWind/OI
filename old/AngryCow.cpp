#include <cstdio>
#include <algorithm>
#define MAXN 100001
using namespace std;
int n,m,x[MAXN],ans;
inline int max(int a,int b)
{
	return a>b?a:b;
}
inline bool check(int d)
{
	int c=1,right=x[1]+d;
	for (int i=2;i<=n;i++)
	{
		if (x[i]>=right)
		{
			right=x[i]+d;
			c++;
		}
		if (c==m) break;
	}
	if (c==m) return true;
	else return false;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	sort(x+1,x+1+n);
	int l=0,r=x[n],mid;
	while (l<r-1)
	{
		mid=(l+r)/2;
		if (check(mid))
		{
			ans=max(ans,mid);
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	printf("%d",ans);
}
//LOJ https://loj.ac/problem/10011
