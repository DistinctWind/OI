#include <cstdio>
using namespace std;
const int MAXN=30001;
int t;
int size[MAXN],d[MAXN],fa[MAXN];
int abs(int x)
{
	return x<0?-x:x;
}
int find(int x)
{
	if (fa[x]==x) return x;
	int root=find(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=root;
}
inline void merge(int x,int y)
{
	x=find(x); y=find(y);
	fa[x]=y; d[x]+=size[y];
	size[y]+=size[x];
}
inline void setup()
{
	for (int i=1;i<MAXN;i++)
		d[i]=0,size[i]=1,fa[i]=i;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	setup();
	while (t--)
	{
		int a,b;
		char tmp;
		scanf(" %c",&tmp);
		switch (tmp)
		{
			case 'M':
				scanf("%d%d",&a,&b);
				merge(a,b);
				break;
			case 'C':
				scanf("%d%d",&a,&b);
				if (find(a)==find(b))
					printf("%d\n",abs(d[a]-d[b])-1);
				else printf("-1\n");
		}
	}
}
