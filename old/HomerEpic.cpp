#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN=100001;
const int MAXK=10;
struct POI{
	ll val,len;
	friend bool operator < (POI a,POI b)
	{
		if (a.val==b.val) return a.len>b.len;
		else return a.val>b.val;
	}
};
int n,k;
ll ans1,ans2;
priority_queue <POI> q;
POI a[MAXK];
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		POI tmp;
		scanf("%lld",&tmp.val);
		tmp.len=0;
		q.push(tmp);
	}
	if ((n-1)%(k-1)!=0)
	{
		ll t=k-1-(n-1)%(k-1);
		POI tmp;
		tmp.val=tmp.len=0;
		while (t--)
		{
			q.push(tmp);
		}
	}
	while (q.size()!=1)
	{
		ll tot=0,maxn=0;
		for (int i=1;i<=k;i++)
		{
			POI now=q.top();
			tot+=now.val;
			maxn=max(maxn,now.len+1);
			q.pop();
		}
		POI tmp;
		tmp.val=tot,tmp.len=maxn;
		ans1+=tmp.val;
		ans2=max(ans2,tmp.len);
		q.push(tmp);
	}
	printf("%lld\n%lld",ans1,ans2);
}
//LGOJ https://www.luogu.org/problem/P2168
//DHOJ http://47.104.154.247/problem.php?cid=1125&pid=5
