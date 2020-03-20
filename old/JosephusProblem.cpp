#include <cstdio>
#include <queue>
using namespace std;
queue <int> q;
int n,m;
int cnt;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		q.push(i);
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		cnt++;
		if (cnt==m)
		{
			printf("%d ",now);
			cnt=0;
		}
		else
			q.push(now);
	}
}
