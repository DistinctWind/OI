#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXM=1e4+1;
char swi[4];
struct Query{
	int l,r,ans;
	inline void get()
	{
		scanf("%d%d %s",&l,&r,swi);
		if (swi[0]=='e') ans=0;
		else if (swi[0]=='o') ans=1;
	}
}q[MAXM];
int n,tmp,m,a[MAXM*2],fa[MAXM*2],d[MAXM*2];
inline void read_discrete()
{
	for (int i=1;i<=m;i++)
	{
		q[i].get();
		a[++tmp]=q[i].l-1;
		a[++tmp]=q[i].r;
	}
	sort(a+1,a+1+tmp);
	n=unique(a+1,a+1+tmp)-a-1;
}
inline void setup()
{
	for (int i=1;i<=2*n;i++)
		fa[i]=i;
}
int query(int x)
{
	return lower_bound(a+1,a+1+n,x)-a;
}
int find(int x)
{
	if (fa[x]==x) return x;
	int root=find(fa[x]);
	d[x]^=d[fa[x]];
	return fa[x]=root;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	read_discrete();
	setup();
	for (int i=1;i<=m;i++)
	{
		int x=query(q[i].l-1);
		int y=query(q[i].r);
		int f=find(x),g=find(y);
		if (f==g)
		{
			if ((d[x]^d[y])!=q[i].ans)
			{
				printf("%d\n",i-1);
				return 0;
			}
		}
		else fa[f]=g,d[f]=d[x]^d[y]^q[i].ans;
	}
	/*for (int i=1;i<=m;i++)
	{
		int x=query(q[i].l-1);
		int y=query(q[i].r);
		int x_odd=x,x_even=x+n;
		int y_odd=y,y_even=y+n;
		if (q[i].ans==0)
		{
			if (find(x_odd)==find(y_even))
			{
				printf("%d\n",i-1);
				return 0;
			}
			fa[find(x_odd)]=find(y_odd);
			fa[find(x_even)]=find(y_even);
		}
		else
		{
			if (find(x_odd)==find(y_odd))
			{
				printf("%d\n",i-1);
				return 0;
			}
			fa[find(x_odd)]=find(y_even);
			fa[find(x_even)]=find(y_odd);
		}
	}*/
	printf("%d\n",m);
}

