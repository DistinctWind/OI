#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN=5e5+10;
int n,t;
ll d[MAXN],p[MAXN],ans=0x3f3f3f3f3f3f3f3fll;
struct State{
	int pos;
	ll pwr,val;
};
bool operator < (State a,State b)
{
	return a.val>b.val;
}
inline void print(State now)
{
	printf("At:%d Pwr=%lld Cost=%lld\n",now.pos,now.pwr,now.val);
}
inline void bfs()
{
	priority_queue <State> q;
	State start;
	start.pos=0,start.pwr=0,start.val=0;
	q.push(start);
	while (!q.empty())
	{
		State h=q.top(); q.pop();
		//print(h);
		if (h.pos==n)
		{
			printf("%lld\n",h.val);
			return;
		}
		if (h.pwr+1<=t)
		{
			State tmp;
			tmp.pwr=h.pwr+1;
			tmp.val=h.val+p[h.pos];
			tmp.pos=h.pos;
			q.push(tmp);
			//print(tmp);
		}
		if (h.pwr>=d[h.pos])
		{
			State tmp;
			tmp.pwr=h.pwr-d[h.pos];
			tmp.val=h.val;
			tmp.pos=h.pos+1;
			q.push(tmp);
			//print(tmp);
		}
	}
}
int main()
{
	freopen("wayhome.in","r",stdin);
	freopen("wayhome.out","w",stdout);
	scanf("%d%d",&n,&t);
	for (int i=0;i<=n;i++)
		scanf("%lld%lld",&d[i],&p[i]);
	bfs();
}
