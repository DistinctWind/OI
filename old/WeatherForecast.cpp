#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=366;
const int mov_x[9]={0,-1,-2,0,0,1,2,0,0};
const int mov_y[9]={0,0,0,1,2,0,0,-1,-2};
struct Calendar{
	bool fes[5][5];
}day[MAXN];
struct state{
	int t,x,y;
	int la,lb,lc,ld;
}start;
int n;
bool vis[MAXN][17][7][7][7][7];
inline void bfs()
{
	queue <state> q;
	q.push(start);
	while (!q.empty())
	{
		state head=q.front();
		q.pop();
		for (int i=0;i<=8;i++)
		{
			 int now_x=head.x+mov_x[i];
			 int now_y=head.y+mov_y[i];
			 if (now_x<1||now_x>3||now_y<1||now_y>3) continue;
			 if (day[head.t+1].fes[now_x][now_y]||day[head.t+1].fes[now_x+1][now_y]||day[head.t+1].fes[now_x][now_y+1]||day[head.t+1].fes[now_x+1][now_y+1])
			 	continue;
			 state tmp;
			 tmp.x=now_x,tmp.y=now_y,tmp.t=head.t+1;
			 if (now_x==1&&now_y==1) tmp.la=0;
			 else tmp.la=head.la+1;
			 if (now_x==3&&now_y==1) tmp.lb=0;
			 else tmp.lb=head.lb+1;
			 if (now_x==1&&now_y==3) tmp.lc=0;
			 else tmp.lc=head.lc+1;
			 if (now_x==3&&now_y==3) tmp.ld=0;
			 else tmp.ld=head.ld+1;
			 int pos=(tmp.x-1)*4+tmp.y;
			 if (tmp.la>6||tmp.lb>6||tmp.lc>6||tmp.ld>6) continue;
			 if (vis[tmp.t][pos][tmp.la][tmp.lb][tmp.lc][tmp.ld]) continue;
		 	 q.push(tmp);
		 	 vis[tmp.t][pos][tmp.la][tmp.lb][tmp.lc][tmp.ld]=true;
		 	 if (tmp.t==n+1)
		 	 {
		 	 	printf("1\n");
		 	 	return;
		 	 }
		}
	}
	printf("0\n");
}
inline void setup()
{
	for (int i=1;i<=n;i++)
	{
		memset(day[i].fes,0,sizeof(day[i].fes));
		memset(vis,0,sizeof(vis));
	}
	start.t=1,start.x=2,start.y=2,start.la=start.lb=start.lc=start.ld=1;
}
int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%d",&n),n!=0)
	{
		setup();
		bool fir=true;
		for (int t=1;t<=n;t++)
		{
			for (int i=1;i<=4;i++)
				for (int j=1;j<=4;j++)
				{
					int tmp;
					scanf("%d",&tmp);
					day[t].fes[i][j]=(tmp==1);
					if (t==1&&2<=i&&i<=3&&2<=j&&j<=3&&day[t].fes[i][j])
						fir=false;
				}
		}
		if (fir) bfs();
		else printf("0\n");
	}
}
