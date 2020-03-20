#include <cstdio>
#include <queue>
using namespace std;
const int MAXN=41;
const int mov_x[5]={0,-1,0,1,0};
const int mov_y[5]={0,0,1,0,-1};
int n;
int mx,my,sx,sy,ex,ey,min_step;
bool map[MAXN][MAXN],go[MAXN][MAXN];
struct poi{
	int x,y,step;
};
void setup()
{
	for (int i=1;i<=MAXN;i++)
		for (int j=1;j<=MAXN;j++)
			map[i][j]=go[i][j]=false;
}
void bfs()
{
	poi start;
	start.x=sx;start.y=sy;start.step=1;
	queue <poi> q;
	q.push(start);
	while (!q.empty())
	{
		poi head;
		head=q.front();
		q.pop();
		if (head.x==ex&&head.y==ey)
		{
			min_step=head.step;
			return;
		}
		for (int i=1;i<=4;i++)
		{
			int now_x=head.x+mov_x[i];
			int now_y=head.y+mov_y[i];
			if (map[now_x][now_y]==true&&go[now_x][now_y]==false)
			{
				poi temp;
				temp.x=now_x;temp.y=now_y;temp.step=head.step+1;
				go[now_x][now_y]=true;
				q.push(temp);
			}
		}
	}
}
void turn(int *now_x,int *now_y,int dir,int x,int y)
{
	switch (dir)
	{
		case 1:*now_x=x-1;*now_y=y;break;
		case 2:*now_x=x;*now_y=y+1;break;
		case 3:*now_x=x+1;*now_y=y;break;
		case 4:*now_x=x;*now_y=y-1;break;
	}
}
int ldfs(int x,int y,int step,int dir)
{
	if (dir==4)
		dir=1;
	else
		dir++;
	if (x==ex&&y==ey)
		return step;
	for (int i=1;i<=4;i++)
	{
		int now_x,now_y;
		turn(&now_x,&now_y,dir,x,y);
		if (map[now_x][now_y]==true)
			return ldfs(now_x,now_y,step+1,dir);
		dir--;
		if (dir==0)
			dir=4;
	}
}
int rdfs(int x,int y,int step,int dir)
{
	if (dir==1)
		dir=4;
	else
		dir--;
	if (x==ex&&y==ey)
		return step;
	for (int i=1;i<=4;i++)
	{
		int now_x,now_y;
		turn(&now_x,&now_y,dir,x,y);
		if (map[now_x][now_y]==true)
			return rdfs(now_x,now_y,step+1,dir);
		dir++;
		if (dir==5)
			dir=1;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&mx,&my);
		setup();
		for (int y=1;y<=my;y++)
			for (int x=1;x<=mx;x++)
			{
				char temp;
				scanf(" %c",&temp);
				switch (temp)
				{
					case '.':map[x][y]=true;break;
					case 'S':sx=x;sy=y;map[x][y]=true;break;
					case 'E':ex=x;ey=y;map[x][y]=true;break;
				}
			}
		bfs();
		printf("%d %d %d\n",ldfs(sx,sy,1,1),rdfs(sx,sy,1,3),min_step);
	}
}
