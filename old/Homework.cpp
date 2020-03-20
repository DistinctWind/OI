#include <cstdio>
#include <algorithm>
#define MAXH 1000001
using namespace std;
struct Homework{
	int e,w;
}h[MAXH];
int n,ans;
bool used[MAXH];
bool operator < (Homework a,Homework b)
{
	return a.w>b.w;
}
int max(int a,int b)
{
	return a>b?a:b;
}
inline void read()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&h[i].e,&h[i].w);
}
inline void solve()
{
	sort(h+1,h+1+n);
	bool flag=false;
	int nt=1;
	for (int i=1;i<=n;i++)
	{
		flag=false;
		for (int j=h[i].e;j>=nt;j--)
		{
			if (used[j]==false)
			{
				flag=true;
				used[j]=true;
				ans+=h[i].w;
				break;
			}
		}
		if (!flag)
			nt=max(nt,h[i].e);
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
