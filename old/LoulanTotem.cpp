#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1e6+1;
struct POI{
	int x,y;
}poi[MAXN];
int c[MAXN],n;
long long ans;
int lowbit(int x)
{
	return x&(-x);
}
inline void update(int pos,int x)
{
	for (;pos<=n;pos+=lowbit(pos))
		c[pos]+=x;
}
long long sum(int pos)
{
	long long res=0;
	for (;pos>0;pos-=lowbit(pos))
		res+=c[pos];
	return res;
}
bool cmp(POI a,POI b)
{
	return a.y>b.y;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&poi[i].y);
		poi[i].x=i;
	}
	sort(poi+1,poi+1+n,cmp);
	for (int i=1;i<=n;i++)
	{
		ans+=sum(poi[i].x-1)*(sum(n)-sum(poi[i].x));
		update(poi[i].x,1);
	}
	printf("%lld ",ans);
	ans=0; memset(c,0,sizeof(c));
	for (int i=n;i>=1;i--)
	{
		ans+=sum(poi[i].x-1)*(sum(n)-sum(poi[i].x));
		update(poi[i].x,1);
	}
	printf("%lld",ans);
}
