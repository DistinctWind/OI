#include <cstdio>
using namespace std;
const int MAXN=1.5e4+5;
const int MAXX=3.2e4+5;
struct STAR{
	int x,y;
}s[MAXN];
int n;
int c[MAXX],ans[MAXN];
int lowbit(int x)
{
	return x&(~x+1);
}
inline void update(int x,int v)
{
	for (;x<=MAXX;x+=lowbit(x))
		c[x]+=v;
}
int sum(int x)
{
	int res=0;
	for (;x>0;x-=lowbit(x))
		res+=c[x];
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&s[i].x,&s[i].y);
	for (int i=1;i<=n;i++)
	{
		int tmp=s[i].x+1;
		int v=sum(tmp);
		update(tmp,1);
		ans[v]++;
	}
	for (int i=0;i<n;i++)
		printf("%d\n",ans[i]);
}
//LOJ https://loj.ac/problem/10114
