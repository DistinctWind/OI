#include <cstdio>
#include <algorithm>
#include <limits.h>
#define MAXN 1001
#define MAXS 100001
using namespace std;
int n,s;
int v[MAXN],minv[MAXS],maxv[MAXS],min_ans[MAXS],max_ans[MAXS];
void print(int *d)
{
	int x=s;
	while (x!=0)
	{
		printf("%d ",d[x]);
		x-=v[d[x]];
	}
	putchar('\n');
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&s);
	for (int i=1;i<=s;i++)
		minv[i]=INT_MAX-1,maxv[i]=INT_MIN+1;
	for (int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for (int i=1;i<=s;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i-v[j]>=0)
			{
				if (minv[i]>minv[i-v[j]]+1)
				{
					minv[i]=minv[i-v[j]]+1;
					min_ans[i]=j;
					//printf("Change minv:minv=%d\n",minv[i]);
				}
				if (maxv[i]<maxv[i-v[j]]+1)
				{
					maxv[i]=maxv[i-v[j]]+1;
					max_ans[i]=j;
					//printf("Change maxv:maxv=%d\n",maxv[i]);
				}
			}
		}
	}
	if (s==0)
	{
		printf("-1 -1\n");
		return 0;
	}
	if (minv[s]!=INT_MAX-1&&maxv[s]!=INT_MIN+1)
	{
		printf("%d %d\n",minv[s],maxv[s]);
		print(min_ans); print(max_ans);
	}
	else
		printf("-1 -1\n");
}
