#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
const int MAXN=501;
struct POI{
	int x,y;
	POI(){
		x=y=0;
	}
};
struct state{
	int cnt,step;
	POI a,b;
	state(){
		cnt=step=0;
	}
	friend bool operator < (state a,state b){
		return a.step<b.step;
	}
}start;
int a[MAXN][MAXN];
int n,m,ex,ey,ans;
bool vis1[MAXN][MAXN],vis2[MAXN][MAXN][2];
state mov(state head,int dir)
{
	state now;
	now.step=head.step+1;
	if (head.cnt==1)
	{
		now.cnt=2;
		switch (dir)
		{
			case 1:
				now.a.x=head.a.x-2;
				now.a.y=head.a.y;
				now.b.x=head.a.x-1;
				now.b.y=head.a.y;
				break;
			case 2:
				now.a.x=head.a.x;
				now.a.y=head.a.y+1;
				now.b.x=head.a.x;
				now.b.y=head.a.y+2;
				break;
			case 3:
				now.a.x=head.a.x+1;
				now.a.y=head.a.y;
				now.b.x=head.a.x+2;
				now.b.y=head.a.y;
				break;
			case 4:
				now.a.x=head.a.x;
				now.a.y=head.a.y-2;
				now.b.x=head.a.x;
				now.b.y=head.a.y-1;
				break;
		}
	}
	else if (head.cnt==2)
	{
		if (head.a.x==head.b.x)
		{
			switch (dir)
			{
				case 1:
					now.cnt=2;
					now.a.x=head.a.x-1;
					now.a.y=head.a.y;
					now.b.x=head.b.x-1;
					now.b.y=head.b.y;
					break;
				case 2:
					now.cnt=1;
					now.a.x=head.b.x;
					now.a.y=head.b.y+1;
					break;
				case 3:
					now.cnt=2;
					now.a.x=head.a.x+1;
					now.a.y=head.a.y;
					now.b.x=head.b.x+1;
					now.b.y=head.b.y;
					break;
				case 4:
					now.cnt=1;
					now.a.x=head.a.x;
					now.a.y=head.a.y-1;
					break;
			}
		}
		else if (head.a.y==head.b.y)
		{
			switch (dir)
			{
				case 1:
					now.cnt=1;
					now.a.x=head.a.x-1;
					now.a.y=head.a.y;
					break;
				case 2:
					now.cnt=2;
					now.a.x=head.a.x;
					now.a.y=head.a.y+1;
					now.b.x=head.b.x;
					now.b.y=head.b.y+1;
					break;
				case 3:
					now.cnt=1;
					now.a.x=head.b.x+1;
					now.a.y=head.b.y;
					break;
				case 4:
					now.cnt=2;
					now.a.x=head.a.x;
					now.a.y=head.a.y-1;
					now.b.x=head.b.x;
					now.b.y=head.b.y-1;
			}
		}
	}
	return now;
}
inline bool judge(state now)
{
	if (now.cnt==1)
	{
		if (now.a.x<1||now.a.x>n) return false;
		if (now.a.y<1||now.a.y>m) return false;
		if (a[now.a.x][now.a.y]==1) return false;
		if (a[now.a.x][now.a.y]==2) return false;
	}
	else if (now.cnt==2)
	{
		if (now.a.x<1||now.a.x>n) return false;
		if (now.a.y<1||now.a.y>m) return false;
		if (now.b.x<1||now.b.x>n) return false;
		if (now.b.y<1||now.b.y>m) return false;
		if (a[now.a.x][now.a.y]==1) return false;
		if (a[now.b.x][now.b.y]==1) return false;
	}
	return true;
}
inline void bfs()
{
	queue <state> q;
	q.push(start);
	if (start.cnt==1)
		vis1[start.a.x][start.a.y]=true;
	else if (start.cnt==2)
		vis2[start.a.x][start.a.y][start.a.x==start.b.x]=true;
	while (!q.empty())
	{
		state head=q.front(); q.pop();
		if (head.cnt==1&&head.a.x==ex&&head.a.y==ey)
		{
			ans=head.step;
			return;
		}
		for (int i=1;i<=4;i++)
		{
			state now=mov(head,i);
			if (!judge(now)) continue;
			if (now.cnt==1)
				if (vis1[now.a.x][now.a.y])
					continue;
			if (now.cnt==2)
				if (vis2[now.a.x][now.a.y][now.a.x==now.b.x])
					continue;
			q.push(now);
			if (now.cnt==1)
				vis1[now.a.x][now.a.y]=true;
			if (now.cnt==2)
				vis2[now.a.x][now.a.y][now.a.x==now.b.x]=true;
		}
	}
}
inline void setup()
{
	ans=-1;
	start.a.x=start.a.y=start.b.x=start.b.y=start.step=start.cnt=0;
	memset(a,0,sizeof(a));
	memset(vis1,0,sizeof(vis1));
	memset(vis2,0,sizeof(vis2));
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%d%d",&n,&m),n!=0&&m!=0)
	{
		setup();
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				char tmp;
				scanf(" %c",&tmp);
				if (tmp=='#') a[i][j]=1;
				else if (tmp=='E') a[i][j]=2;
				else if (tmp=='X')
				{
					start.cnt++;
					if (start.cnt==1) start.a.x=i,start.a.y=j;
					else if (start.cnt==2) start.b.x=i,start.b.y=j;
				}
				else if (tmp=='O')
					ex=i,ey=j;
			}
		bfs();
		if (ans!=-1) printf("%d\n",ans);
		else printf("Impossible\n");
	}
}
