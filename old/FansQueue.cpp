#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=50010;
int len,n,ans=0x3f3f3f3f;
int a[MAXN];
int f(int *num,int k)
{
	int l=1,r=len,res;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (num[mid]<=k) res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
inline void cpy(int *x,int *y)
{
	for (int i=1;i<=n;i++)
		x[i]=y[i];
}
bool check()
{
	for (int i=1;i<n;i++)
		if (a[i]>a[i+1])
			return false;
	return true;
}
inline void putfront(int i)
{
	int tmp=a[i];
	for (int j=i;j>=2;j--)
		a[j]=a[j-1];
	a[1]=tmp;
}
inline void putback(int i)
{
	int tmp=a[i];
	for (int j=i;j<n;j++)
		a[j]=a[j+1];
	a[n]=tmp;
}
int x[MAXN],tmp[MAXN],cnt;
void msort(int l,int r)
{
	if (l==r) return;
	int mid=l+r>>1;
	msort(l,mid); msort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while (i<=mid&&j<=r)
	{
		if (x[i]<x[j])
		{
			tmp[k++]=x[i++];
		}
		else
		{
			cnt+=mid-i+1;
			tmp[k++]=x[j++];
		}
	}
	while (i<=mid) tmp[k++]=x[i++];
	while (j<=r) tmp[k++]=x[j++];
	for (int p=l;p<=r;p++)
		x[p]=tmp[p];
}
inline void dfs(int step)
{
	if (step>=ans) return;
	if (check())
	{
		ans=min(ans,step);
		return;
	}
	cnt=0; cpy(x,a); msort(1,n);
	int b[MAXN],delta=cnt;
	cpy(b,a);
	for (int i=2;i<=n;i++)
	{
		putfront(i);
		cnt=0; cpy(x,a); msort(1,n);
		if (cnt<delta) dfs(step+1);
		cpy(a,b);
	}
	for (int i=1;i<n;i++)
	{
		putback(i);
		cnt=0; cpy(x,a); msort(1,n);
		if (cnt<delta) dfs(step+1);
		cpy(a,b);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(0);
	printf("%d",ans);
}
