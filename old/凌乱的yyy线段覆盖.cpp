#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=1000010;
int n;
struct Range{
	int l,r;
}range[MAXN];
bool cmp(Range a,Range b)
{
	return a.r<b.r;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&range[i].l,&range[i].r);
	sort(range+1,range+1+n,cmp);
	int t=0;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (t<=range[i].l)
		{
			t=range[i].r;
			ans++;
		}
	}
	printf("%d",ans);
}
