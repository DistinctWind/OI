#include <cstdio>
#include <algorithm>
#define MAXN 1001
#define MAXM 100001
using namespace std;
struct Plan{
	int x,y,t;
	friend bool operator < (Plan a,Plan b)
	{
		return a.t<b.t;
	}
}p[MAXM];
int n,m,f[MAXN];
int find(int a)
{
	if (f[a]!=a) f[a]=find(f[a]);
	return f[a];
}
void contact(int a,int b)
{
	int f1=find(a),f2=find(b);
	if (f1!=f2) f[f1]=f2;
}
bool judge()
{
	int tf=find(1);
	bool ok=true;
	for (int i=2;i<=n&&ok;i++)
		if (find(i)!=tf)
			ok=false;
	return ok;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		f[i]=i;
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].t);
	sort(p+1,p+1+m);
	for (int i=1;i<=m;i++)
	{
		contact(p[i].x,p[i].y);
		if (judge())
		{
			printf("%d\n",p[i].t);
			return 0;
		}
	}
	printf("-1\n");
}
//LGOJ https://www.luogu.org/problemnew/show/P1111
