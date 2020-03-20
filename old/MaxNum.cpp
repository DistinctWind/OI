#include <cstdio>
using namespace std;
const int MAXN=10001;
int n,num[MAXN],ans,cnt;
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	num[0]=num[1]-1;
	for (int i=1;i<=n;i++)
	{
		if (num[i]==num[i-1]+1)
		{
			cnt++;
		}
		else ans=max(ans,cnt),cnt=1;
	}
	printf("%d",ans);
}
