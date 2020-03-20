#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=110;
int t,n,ans,a[MAXN],mk[250000];
inline void setup()
{
	memset(a,0,sizeof(a));
	memset(mk,0,sizeof(mk));
	ans=0;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		setup();
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]),mk[a[i]]=2;
		sort(a+1,a+1+n);
		for (int i=1;i<=a[n];i++)
		{
			if (mk[i]<=0) continue;
			for (int j=1;j<=n;j++)
			{
				if (i+a[j]<=a[n]) mk[i+a[j]]=1;
				else break;
			}
		}
		for (int i=1;i<=a[n];i++)
			if (mk[i]==2)
				ans++;
		printf("%d\n",ans);
	}
}
