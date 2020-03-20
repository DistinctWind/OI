#include <cstdio>
#define MAXN 100001
using namespace std;
int n,m;
int num[MAXN],sum[MAXN],maxn=-1;
int max(int a,int b)
{
	return a>b?a:b;
}
bool check(int mid)
{
	int pos=0,tmp=1,cnt=m;
	while (cnt--)
	{
		while (sum[tmp]-sum[pos]<mid&&tmp<=n) tmp++;
		pos=--tmp;
	}
	if (pos<n) return false;
	return true;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		sum[i]=sum[i-1]+num[i];
		maxn=max(maxn,num[i]);
	}
	int l=maxn,r=sum[n],mid;
	while (r-l>1)
	{
		mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%d",l);
}
