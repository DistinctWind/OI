#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=100010;
int n,m;
int a[MAXN];
bool check(int mid)
{
	int now=a[1],cnt=1;
	for (int i=2;i<=n;i++)
	{
		if (a[i]-now>=mid)
		{
			cnt++;
			now=a[i];
		}
	}
	return cnt>=m;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int l=0,r=0x3f3f3f3f,ans;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}
