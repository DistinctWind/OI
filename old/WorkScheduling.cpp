#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 100001
using namespace std;
struct state{
	int d,p;
	friend bool operator < (state a,state b)
	{
		return a.d<b.d;
	}
}s[MAXN];
int n;
long long ans;
priority_queue <int,vector<int>,greater<int> > q;
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&s[i].d,&s[i].p);
	sort(s+1,s+1+n);
	for (int i=1;i<=n;i++)
	{
		if (s[i].d<=q.size())
		{
			if (s[i].p>q.top())
			{
				ans-=q.top();
				q.pop();
				q.push(s[i].p);
				ans+=s[i].p;
			}
		}
		else
		{
			ans+=s[i].p;
			q.push(s[i].p);
		}
	}
	printf("%lld",ans);
}
