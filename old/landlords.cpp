#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=20;
struct State{
	int c[MAXN],step;
	void cpy(int *itm)
	{
		for (int i=0;i<=13;i++)
			c[i]=itm[i];
	}
	bool clr()
	{
		bool ok=true;
		for (int i=0;i<=13&&ok;i++)
			if (c[i]!=0)
				ok=false;
		return ok;
	}
};
int t,n,limit;
int cnt[MAXN];
int nxt(int j)
{
	if (j==0) return -1;
	if (j==1) return 2;
	if (j==2) return 0;
	if (j+1>13) return 1;
	return j+1;
}
bool check(int s,int *c)
{
	switch (s)
	{
		case 1:
			if (c[0]==2)
			{
				c[0]=0;
				return true;
			}
			return false;
		case 2:
			for (int i=1;i<=13;i++)
				if (c[i]==4)
				{
					c[i]=0;
					return true;
				}
			return false;
		case 3:
			for (int i=1;i<=13;i++)
				if (c[i]>=1)
				{
					c[i]--;
					return true;
				}
			return false;
		case 4:
			for (int i=1;i<=13;i++)
				if (c[i]>=2)
				{
					c[i]-=2;
					return true;
				}
			return false;
		case 5:
			for (int i=1;i<=13;i++)
				if (c[i]>=3)
				{
					c[i]-=3;
					return true;
				}
			return false;
		case 6:
			for (int i=1;i<=13;i++)
				for (int j=1;j<=13;j++)
					if (c[i]>=3&&c[j]>=1)
					{
						c[i]-=3;
						c[j]--;
						return true;
					}
			return false;
		case 7:
			for (int i=1;i<=13;i++)
				for (int j=1;j<=13;j++)
					if (c[i]>=3&&c[j]>=2)
					{
						c[i]-=3;
						c[j]-=2;
						return true;
					}
			return false;
	}
}
inline int bfs()
{
	queue <State> q;
	State start;
	start.cpy(cnt); start.step=0;
	q.push(start);
	while (!q.empty())
	{
		State h=q.front(); q.pop();
		if (h.clr()) return h.step;
		State tmp=h; tmp.step++;
		for (int i=1;i<=limit;i++)
			if (check(i,tmp.c))
			{
				q.push(tmp);
				tmp.cpy(h.c);
			}
	}
}
int main()
{
	//freopen("landlords.in","r",stdin);
	//freopen("landlords.out","w",stdout);
	scanf("%d%d",&t,&n);
	limit=6;
	while (t--)
	{
		memset(cnt,0,sizeof(cnt));
		for (int i=1,now,col;i<=n;i++)
		{
			scanf("%d%d",&now,&col);
			cnt[now]++;
		}
		printf("%d\n",bfs());
	}
}
