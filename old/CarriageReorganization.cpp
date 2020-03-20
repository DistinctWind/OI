#include <cstdio>
using namespace std;
const int MAXN=1e4+1;
int n,a[MAXN],t[MAXN];
long long ans;
void msort(int l,int r)
{
	if (l==r) return;
	int mid=l+r>>1;
	msort(l,mid);
	msort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while (i<=mid&&j<=r)
	{
		if (a[i]<a[j])
			t[k++]=a[i++];
		else
		{
			t[k++]=a[j++];
			ans+=mid-i+1;
		}
	}
	while (i<=mid)
		t[k++]=a[i++];
	while (j<=r)
		t[k++]=a[j++];
	for (int i=l;i<=r;i++)
		a[i]=t[i];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	msort(1,n);
	printf("%lld",ans);
}
