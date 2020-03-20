#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=1001;
const int MAXNUM=999999+1;
const char case1[]="ENQUEUE";
const char case2[]="DEQUEUE";
const char stop[]="STOP";
int team[MAXNUM],n,cnt;
char ord[7];
queue <int> q[MAXN];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%d",&n),n!=0)
	{
		cnt++;
		printf("Scenario #%d\n",cnt);
		memset(team,0,sizeof(team));
		for (int i=1;i<=n;i++)
		{
			int num;
			scanf("%d",&num);
			for (int j=1;j<=num;j++)
			{
				int tmp;
				scanf("%d",&tmp);
				team[tmp]=i;
			}
		}
		while (scanf(" %s",ord),strcmp(ord,stop)!=0)
		{
			if (strcmp(ord,case1)==0)
			{
				int tmp;
				scanf("%d",&tmp);
				if (q[team[tmp]].empty())
					q[0].push(team[tmp]);
				q[team[tmp]].push(tmp);
			}
			if (strcmp(ord,case2)==0)
			{
				int t=q[0].front();
				int ans=q[t].front(); q[t].pop();
				if (q[t].empty())
					q[0].pop();
				printf("%d\n",ans);
			}
		}
		for (int i=0;i<=n;i++)
			while (!q[i].empty())
				q[i].pop();
		putchar('\n');
	}
}
