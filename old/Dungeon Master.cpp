#include <cstdio>
#include <queue>
using namespace std;
const int MAXN=31;
const int mov_x[7]={0,0,0,1,-1,0,0};
const int mov_y[7]={0,0,0,0,0,-1,1};
const int mov_z[7]={0,1,-1,0,0,0,0};
//from one to six
//up,down,right,left,front,behind
int sx,sy,sz;
int mx,my,mz;
int ex,ey,ez;
bool go[MAXN][MAXN][MAXN];
char map[MAXN][MAXN][MAXN];
struct node{
	int x,y,z,step;
};
queue <node> q;
void bfs()
{
	node start;
	start.x=sx;
	start.y=sy;
	start.z=sz;
	start.step=0;
	q.push(start);
	while (!q.empty())
	{
		node head;
		head=q.front();
		q.pop();
		if (head.x==ex&&head.y==ey&&head.z==ez)
		{
			printf("Escaped in %d minute(s).\n",head.step);
			return;
		}
		for (int i=1;i<=6;i++)
		{
			int now_x=head.x+mov_x[i];
			int now_y=head.y+mov_y[i];
			int now_z=head.z+mov_z[i];
			if (1<=now_x&&now_x<=mx&&1<=now_y&&now_y<=my&&1<=now_z&&now_z<=mz&&go[now_x][now_y][now_z]==true)
			{
				go[now_x][now_y][now_z]=false;
				node temp;
				temp.x=now_x;
				temp.y=now_y;
				temp.z=now_z;
				temp.step=head.step+1;
				q.push(temp);
			}
		}
	}
	printf("Trapped!\n");
	return;
}
int main()
{
	while (true)
	{
		scanf("%d%d%d",&mz,&my,&mx);
		if (mx==0&&my==0&&mz==0)
			break;
		for (int i=1;i<MAXN;i++)
			for (int j=1;j<MAXN;j++)
				for (int k=1;k<MAXN;k++)
					go[i][j][k]=true;
		while (!q.empty())
			q.pop();
		for (int i=1;i<=mz;i++)
			for (int j=1;j<=my;j++)
				for (int k=1;k<=mx;k++)
				{
					scanf(" %c",&map[k][j][i]);
					if (map[k][j][i]=='S')
					{
						sx=k;
						sy=j;
						sz=i;
					}
					if (map[k][j][i]=='#')
						go[k][j][i]=false;
					if (map[k][j][i]=='E')
					{
						ex=k;
						ey=j;
						ez=i;
					}
				}
		bfs();
	}
}
//http://47.104.154.247/problem.php?cid=1080&pid=0
