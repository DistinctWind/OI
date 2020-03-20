#include <cstdio>
using namespace std;
const int MAXN=1e4+10;
int n,m;
int fa[MAXN];
inline void setup()
{
	for (int i=1;i<=n;i++)
		fa[i]=i;
}
int find(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int a,int b)
{
	int f1=find(a);
	int f2=find(b);
	if (f1!=f2) fa[f1]=f2;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	setup();
	for (int i=1,z,x,y;i<=m;i++)
	{
		scanf("%d%d%d",&z,&x,&y);
		if (z==1)
		{
			merge(x,y);
		}
		else
		{
			if (find(x)==find(y)) printf("Y\n");
			else printf("N\n");
		}
	}
}
