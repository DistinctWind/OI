#include <cstdio>
using namespace std;
const int MAXN=5e4+1;
int n,k,fa[MAXN*3],ans;
inline void setup()
{
	for (int i=1;i<=3*n;i++)
		fa[i]=i;
}
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	setup();
	for (int i=1;i<=k;i++)
	{
		int swi,x,y;
		scanf("%d%d%d",&swi,&x,&y);
		int xs=x,xe=x+n,xo=x+n+n;
		int ys=y,ye=y+n,yo=y+n+n;
		if (x>n||y>n)
		{
			ans++;
			continue;
		}
		if (swi==1)
		{
			if (find(xs)==find(ye)||find(xe)==find(ys))
			{
				ans++;
				continue;
			}
			fa[find(xs)]=find(ys);
			fa[find(xe)]=find(ye);
			fa[find(xo)]=find(yo);
		}
		if (swi==2)
		{
			if (find(xs)==find(ys)||find(xs)==find(ye))
			{
				ans++;
				continue;
			}
			fa[find(xs)]=find(yo);
			fa[find(xe)]=find(ys);
			fa[find(xo)]=find(ye);
		}
	}
	printf("%d",ans);
}
