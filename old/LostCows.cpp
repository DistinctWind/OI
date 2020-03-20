#include <cstdio>
using namespace std;
const int MAXN=1e5+1;
int a[MAXN],c[MAXN],n,ans,sum;
int log[MAXN],h[MAXN];
int lowbit(int x)
{
	return x&(-x);
}
inline void insert(int pos,int x)
{
	for (;pos<=n;pos+=lowbit(pos))
		c[pos]+=x;
}
int query(int pos)
{
	int res=0;
	for (;pos>0;pos-=lowbit(pos))
		res+=c[pos];
	return res;
}
inline void setup()
{
	log[0]=-1;
	for (int i=1;i<=n;i++)
	{
		log[i]=log[i>>1]+1;
		insert(i,1);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
		scanf("%d",&a[i]);
	setup();
	for (int i=n;i>=1;i--)
	{
		int l=1,r=n;
		while (l<r)
		{
			int mid=l+r>>1;
			if (query(mid)<a[i]+1) l=mid+1;
			else r=mid;
		}
		h[i]=l;
		insert(h[i],-1);
	}
	for (int i=1;i<=n;i++)
		printf("%d\n",h[i]);
}
