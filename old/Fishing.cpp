#include <cstdio>
#include <queue>
#define MAXN 10001
using namespace std;
struct state{
	int f,num;
	bool operator < (state b)const
	{
		return f<b.f;
	}
}a[MAXN];
int n,h,d[MAXN],t[MAXN-1],ans;
priority_queue <state> q;
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	scanf("%d%d",&n,&h);
	h*=12;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].f);
		a[i].num=i;
	}
	for (int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	for (int i=1;i<=n-1;i++)
		scanf("%d",&t[i]);
	for (int i=1;i<=n;i++)
	{
		h-=t[i-1];
		int now=0;
		while (!q.empty())
			q.pop();
		for (int j=1;j<=i;j++)
			q.push(a[j]);
		for (int j=1;j<=h;j++)
		{
			state s=q.top();
			q.pop();
			now+=s.f;
			s.f=max(0,s.f-d[s.num]);
			q.push(s);
		}
		ans=max(ans,now);
	}
	printf("%d",ans);
}
