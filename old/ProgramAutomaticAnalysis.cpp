#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN=100001;
struct Merge{
	int a,b;
}mer[MAXN*2];
struct Judgement{
	int a,b;
}jud[MAXN*2];
int t,n,m,cnt,tot1,tot2,fa[MAXN*2],a[MAXN*2],b[MAXN*2];
inline void setup()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(mer,0,sizeof(mer));
	memset(jud,0,sizeof(jud));
	cnt=tot1=tot2=m=0;
	for (int i=1;i<MAXN*2;i++)
		fa[i]=i;
}
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int a,int b)
{
	fa[find(a)]=find(b);
}
inline void discrete()
{
	sort(a+1,a+1+cnt);
	for (int i=1;i<=cnt;i++)
		if (i==1||a[i]!=a[i-1])
			b[++m]=a[i];
}
int query(int x)
{
	return lower_bound(b+1,b+1+m,x)-b;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		setup();
		for (int i=1;i<=n;i++)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			if (k==1)
			{
				cnt++; tot1++;
				mer[tot1].a=a[cnt]=x;
				cnt++;
				mer[tot1].b=a[cnt]=y;
			}
			else if (k==0)
			{
				cnt++; tot2++;
				jud[tot2].a=a[cnt]=x;
				cnt++;
				jud[tot2].b=a[cnt]=y;
			}
		}
		discrete();
		for (int i=1;i<=tot1;i++)
		{
			merge(query(mer[i].a),query(mer[i].b));
		}
		bool ans=true;
		for (int i=1;i<=tot2&&ans;i++)
		{
			if (find(query(jud[i].a))==find(query(jud[i].b)))
				ans=false;
		}
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
}
//LGOJ https://www.luogu.org/problem/P1955
