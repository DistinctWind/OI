#include <cstdio>
#include <algorithm>
#define MAXL 1000001
using namespace std;
struct Line{
	int s,e;
}l[MAXL];
int n,ans;
bool operator < (Line a,Line b)
{
	return a.e<b.e;
}
inline void read()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&l[i].s,&l[i].e);
}
inline void solve()
{
	sort(l+1,l+1+n);
	int x=0;
	for (int i=1;i<=n;i++)
	{
		if (x<=l[i].s)
		{
			x=l[i].e;
			ans++;
		}
	}
}
inline void out()
{
	printf("%d\n",ans);
}
int main()
{
	read();
	solve();
	out();
}
