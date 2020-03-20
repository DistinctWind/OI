#include <cstdio>
using namespace std;
const int MAXN=60010;
int n;
int a[MAXN],tmp[MAXN];
long long ans;
void msort(int l,int r)
{
	if (l==r) return;
	int mid=l+r>>1;
	msort(l,mid); msort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while (i<=mid&&j<=r)
	{
		if (a[i]>a[j])
		{
			ans+=mid-i+1;
			tmp[k++]=a[j++];
		}
		else
		{
			tmp[k++]=a[i++];
		}
	}
	while (i<=mid)
		tmp[k++]=a[i++];
	while (j<=r)
		tmp[k++]=a[j++];
	for (int x=l;x<=r;x++)
		a[x]=tmp[x];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	msort(1,n);
	printf("%lld",ans);
}
